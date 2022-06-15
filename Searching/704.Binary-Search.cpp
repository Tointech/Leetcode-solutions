#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Using loop
    int search1(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while(left <= right) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
    // Time Complexity: O(log(n)); Space Complexity: O(1)

    // Using recursion
    int search2(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }

        int mid = (left + right) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target > nums[mid]) {
            return search2(nums, target, mid + 1, right);
        } else {
            return search2(nums, target, left, mid - 1);
        }
    } // Overwrite function

    int search2(vector<int>& nums, int target) {
        int n = nums.size();
        return search2(nums, target, 0, n - 1);
    }
    // Time Complexity: O(log(n)); Space Complexity: O(log(n))
};

int main() {
    vector<int> nums = {1, 6, 7, 8, 9, 10, 12, 14, 20, 25, 31};
    int target = 12;

    Solution obj;
    cout << obj.search2(nums, target) << endl;

    return 0;
}