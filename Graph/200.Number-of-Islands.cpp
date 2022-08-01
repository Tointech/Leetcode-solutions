#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool visited[300][300];
    int row;
    int col;

public:
    bool isValid (int i, int j) {
        return i >= 0 && j >= 0 && i < row && j < col;
    }

    void DFS(vector<vector<char>>& grid, int i, int j) {
        if(!isValid(i, j)) {
            return;
        } 

        if (grid[i][j] == '0' || visited[i][j] == true) {
            return;
        }

        visited[i][j] = true;

        // Recursion
        DFS(grid, i, j+1);
        DFS(grid, i, j-1);
        DFS(grid, i+1, j);
        DFS(grid, i-1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        row = grid.size();
        col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    count++;
                    DFS(grid, i, j);
                }
            }
        }
        return count;    
    }
};

int main() { 

    return 0;
}
