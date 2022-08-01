#include <bits/stdc++.h>

using namespace std;

class MyDijkstra {
    static const int n = 5;
    static const int oo = INT_MAX;
    vector<int> visited;
    int distance[n];
    int previous[n];

public:
    int graph[n][n] =   {   {0, 6, 0, 1, 0}, 
                            {6, 0, 5, 2, 2}, 
                            {0, 5, 0, 0, 5}, 
                            {1, 2, 0, 0, 1}, 
                            {0, 2, 5, 1, 0}     };  

    void dijkstra() {
        int start, finish;
        cout << "Input start and finish point: "; cin >> start >> finish;

        for (int i = 0; i < n; i++) {
            distance[i] = oo;
        }
        distance[start] = 0;

        while(visited.size() < n) {
            int current = 0;
            int minDis = oo;
            for (int i = 0; i < n; i++) {
                if (find(visited.begin(), visited.end(), i) == visited.end() && distance[i] < minDis) {
                    minDis = distance[i];
                    current = i;
                }
            }

            for (int i = 0; i < n; i++) {
                if (find(visited.begin(), visited.end(), i) == visited.end() && graph[current][i] != 0) {
                    int newDistance = distance[current] + graph[current][i];
                    if (newDistance < distance[i]) {
                        distance[i] = newDistance;
                        previous[i] = current;
                    }
                }
            }

            visited.push_back(current);
        }

        cout << "Min distance from " << start << " to " << finish << " is: " << distance[finish] << endl; 

        cout << "Path is: "; 

        // Truy vet
        int run = finish;
        while (run != start) {
            cout << run << "<-";
            run = previous[run];
        }
        cout << run << endl;
    }
};

int main() {
    MyDijkstra obj;
    obj.dijkstra();

    return 0;
}
