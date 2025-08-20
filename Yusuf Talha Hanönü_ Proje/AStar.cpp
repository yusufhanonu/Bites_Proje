#include "AStar.h"
#include <queue>
#include <thread>
#include <chrono>
#include <cmath>
#include <climits>

using namespace std;

struct Node {
    int x, y;
    int gCost, hCost;
    Node* parent;

    Node(int _x, int _y, int _g, int _h, Node* _p = nullptr)
        : x(_x), y(_y), gCost(_g), hCost(_h), parent(_p) {}

    int fCost() const { return gCost + hCost; }
};

static inline int heuristic(int x1, int y1, int x2, int y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

void astarPathFind(vector<vector<Proje>> &vProje) {
    pair<int,int> start{-1,-1}, goal{-1,-1};
    for (int i = 0; i < Boyut; i++) {
        for (int j = 0; j < Boyut; j++) {
            if (vProje[i][j].getYazi() == 'S') start = {i, j};
            if (vProje[i][j].getYazi() == 'G') goal  = {i, j};
        }
    }

    if (start.first == -1 || goal.first == -1) {
        cout << "A*: Start (S) veya Goal (G) bulunamadi.\n";
        return;
    }
    if (vProje[start.first][start.second].getYazi() == 'X' ||
        vProje[goal.first][goal.second].getYazi()  == 'X') {
        cout << "A*: S veya G engel ile kapali.\n";
        return;
    }

    auto cmp = [](Node* a, Node* b) { return a->fCost() > b->fCost(); };
    priority_queue<Node*, vector<Node*>, decltype(cmp)> openList(cmp);

    vector<vector<bool>> closed(Boyut, vector<bool>(Boyut, false));
    vector<vector<int>>  gBest (Boyut, vector<int>(Boyut, INT_MAX));

    Node* startNode = new Node(start.first, start.second, 0,
                               heuristic(start.first, start.second, goal.first, goal.second),
                               nullptr);
    openList.push(startNode);
    gBest[start.first][start.second] = 0;

    vector<Node*> allocated{startNode};

    const pair<int,int> dirs[4] = {{1,0},{-1,0},{0,1},{0,-1}};

    Node* endNode = nullptr;

    while (!openList.empty()) {
        Node* current = openList.top();
        openList.pop();

        if (closed[current->x][current->y]) continue;
        closed[current->x][current->y] = true;

        if (current->x == goal.first && current->y == goal.second) {
            endNode = current;
            break;
        }
        
        char here = vProje[current->x][current->y].getYazi();
        if (here != 'S' && here != 'G' && here != 'X') {
            vProje[current->x][current->y].setYazi('.');
            matrisYazdir(vProje);
            this_thread::sleep_for(chrono::milliseconds(1000));
        }

        for (auto [dx, dy] : dirs) {
            int nx = current->x + dx;
            int ny = current->y + dy;

            if (nx < 0 || ny < 0 || nx >= Boyut || ny >= Boyut) continue;
            if (vProje[nx][ny].getYazi() == 'X') continue;
            if (closed[nx][ny]) continue;

            int tentativeG = current->gCost + 1;

            if (tentativeG < gBest[nx][ny]) {
                gBest[nx][ny] = tentativeG;
                int h = heuristic(nx, ny, goal.first, goal.second);
                Node* next = new Node(nx, ny, tentativeG, h, current);
                openList.push(next);
                allocated.push_back(next);
            }
        }
    }

    if (!endNode) {
        cout << "A*: Yol bulunamadi.\n";
        for (auto p : allocated) delete p;
        return;
    }

    Node* p = endNode->parent;
    while (p && !(p->x == start.first && p->y == start.second)) {
        if (vProje[p->x][p->y].getYazi() != 'S' && vProje[p->x][p->y].getYazi() != 'G') {
            vProje[p->x][p->y].setYazi('1');
            matrisYazdir(vProje);
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
        p = p->parent;
    }

    matrisYazdir(vProje);

    for (auto q : allocated) delete q;
}