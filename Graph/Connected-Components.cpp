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
        adj[w].push_back(v);
    }

    // Depth First Search
    void DFS(int v) {
        visited[v] = true;
        cout << v << " ";

        vector<int> i;
        for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
            if (!visited[*i]) {
                DFS(*i);
            }
        }
    }

    void connectedComponents() {
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                DFS(i);
                cout << "\n";
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "\nConnected components: ";
    g.connectedComponents();

    return 0;
}
