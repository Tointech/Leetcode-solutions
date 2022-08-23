#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        for (int i = 0; i < n; ) {
            if (nums[i] == val) {
                for (int j = i; j < n - 1; j++) {
                    nums[j] = nums[j + 1];
                }
                n--;
            } else {
                i++;
            }
        }

        return n;
    }
};

int main() {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;

    Solution obj;
    cout << obj.removeElement(nums, val) << endl;

    return 0;
}