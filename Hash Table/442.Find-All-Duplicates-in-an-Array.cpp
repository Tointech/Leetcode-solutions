#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i])-1] > 0)
                nums[abs(nums[i])-1]  = -nums[abs(nums[i])-1] ;
            else 
                ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {5, 6, 7, 4, 3, 2, 7, 8, 2, 3, 1};
    Solution obj;

    vector<int> result;
    result = obj.findDuplicates(nums);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}