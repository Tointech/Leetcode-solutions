#include <bits/stdc++.h>

using namespace std;

class Graph {
    int v; // number of vertices
    vector<vector<int>> adj; /// adjacency lists
    vector<bool> visited; // vertices visited

public:
    Graph(int v) {
        this->v = v;
        adj.resize(v);
        visited.resize(v, false);
    }
    
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    // Depth First Search
    void DFS(int v, stack<int> &Stack) {
        visited[v] = true;

        vector<int> i;
        for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
            if (!visited[*i]) {
                DFS(*i, Stack);
            }
        }

        Stack.push(v);
    }

    void topologicalSort() {
        stack<int> Stack;

        for (int i = 0; i < v; i++) {
            visited[i] = false;
        }
        for (int i = 0; i < v; i++) {
            if (visited[i] == false)
                DFS(i, Stack);
        }
        while(!Stack.empty()) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "\nFollowing is a Topological Sort of the given graph: ";
    g.topologicalSort();

    return 0;
}
