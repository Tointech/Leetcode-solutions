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

    // Implement with stack
    void stackDFS (int start) {
        stack<int> s;
        s.push(start);

        vector<bool> visited;
        visited.resize(SIZE, false);
        visited[start] = true;

        while(!s.empty()) {
            int u = s.top();
            s.pop();
            cout << u << " ";

            for (int v = 0; v < SIZE; v++) {
                if (graph[u][v] == 1 && !visited[v]) {
                    s.push(v);
                    visited[v] = true;
                }
            }
        }

        cout << endl;
    }

    // Implement with recursion
    void recursion(int u, vector<bool> visited) {
        cout << u << " ";
        
        for (int v = SIZE - 1; v >= 0; v--) {
            if (graph[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                recursion(v, visited);
            }
        }
    }

    void recursionDFS(int start) {
        vector<bool> visited;
        visited.resize(SIZE, false);
        visited[start] = true;

        recursion(start, visited);
        cout << endl;
    }

};

int main() { 
    int start;
    cout << "Input starting vertex: "; cin >> start;
    
    DFS obj;
    cout << "Depth First Traversal using Stack (starting form vertex " << start << "): ";
    obj.stackDFS(start);

    cout << "Depth First Traversal using Recursion (starting form vertex " << start << "): ";
    obj.recursionDFS(start);

    return 0;
}
