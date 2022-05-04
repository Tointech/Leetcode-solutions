#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size();
        int n = accounts[0].size();
        int maxWealth = 0;

        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += accounts[i][j];
            }
            if (sum > maxWealth) {
                maxWealth = sum;
            }
        }

        return maxWealth; 
    }
};

int main() {
    vector<vector<int>> accounts = {{1,2,3},{3,2,1}};

    Solution obj;
    cout << obj.maximumWealth(accounts);
    return 0;
}