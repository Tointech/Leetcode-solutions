#include <bits/stdc++.h>
#define SIZE 7
using namespace std;

class DFS {
public:
    int graph[SIZE][SIZE] = {   {0, 1, 0, 0, 0, 0, 0},
                                {1, 0, 1, 1, 1, 0, 0},
                                {0, 1, 0, 0, 0, 1, 0},
                                {0, 1, 0, 0, 0, 1, 1},
                                {0, 1, 0, 0, 0, 0, 1},
                                {0, 0, 1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 1, 0, 0}   };

    // Implement with queue
    void BFS (int start) {
        queue<int> q;
        q.push(start);

        vector<bool> visited;
        visited.resize(SIZE, false);
        visited[start] = true;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v = 0; v < SIZE; v++) {
                if (graph[u][v] == 1 && !visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }

        cout << endl;
    }
};

int main() { 
    int start;
    cout << "Input starting vertex: "; cin >> start;
    
    DFS obj;
    cout << "Breadth First Traversal (starting form vertex " << start << "): ";
    obj.BFS(start);  

    return 0;
}
