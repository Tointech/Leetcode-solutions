#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int k = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

int main() {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;

    Solution obj;
    cout << obj.removeElement(nums, val) << endl;

    return 0;
}