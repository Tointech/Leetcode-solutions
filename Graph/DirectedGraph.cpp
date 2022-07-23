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

    // Breadth First Search
    void BFS(int s) {
        list<int> queue;
        
        visited[s] = true;
        queue.push_back(s);

        while(!queue.empty()) {
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            for (auto adjacent:adj[s]) {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    int start;
    cout << "Input starting vertex: "; cin >> start;

    // cout << "Depth First Traversal (starting form vertex " << start << "): ";
    // g.DFS(start);
    
    cout << "Breadth First Traversal (starting form vertex " << start << "): ";
    g.BFS(start);  

    return 0;
}
