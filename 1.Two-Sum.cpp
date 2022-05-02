#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector <int> targetSum(vector <int> &nums , int &target) {
        int n = nums.size();

        for(int i = 0 ; i < n - 1 ; i++)
            for(int j = i + 1 ; j < n ; j++) {
                if(nums[i] + nums[j] == target)
                    return {i, j};
            }

        return {};
    }
};

int main() {
    vector <int> arr = {1 , 4 , 5 , 11 , 12};
    int targetNum = 9;

    Solution obj;
    for(int &x : obj.targetSum(arr, targetNum))
        cout << x << " ";
    cout << '\n';

    return 0;
}
