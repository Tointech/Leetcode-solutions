#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        bool flag = false;

        // Find first largest element
        long max1 = nums[0];
        for (int i = 1; i < n ; i++) {
            if (nums[i] > max1) {
                max1 = nums[i];
            }
        }
    
        // Find second largest element
        long max2 = LONG_MIN;
        for (int i = 0; i < n ; i++) {
            if (nums[i] > max2 && nums[i] < max1) {
                max2 = nums[i];
            }
        }
    
        // Find third largest element
        long max3 = LONG_MIN;
        for (int i = 0; i < n ; i++) {
            if (nums[i] > max3 && nums[i] < max2) {
                max3 = nums[i];
                flag = true;
            }
        }

        if (flag) return max3;
        return max1;
    }
};

int main() {
    vector<int> nums = {2, 1, 2, 3};

    Solution obj;
    cout << obj.thirdMax(nums) << endl;

    return 0;
}