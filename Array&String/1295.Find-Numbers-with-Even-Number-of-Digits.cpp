#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            int countDigits = 0;

            while (nums[i] != 0) {
                countDigits++;
                nums[i] /= 10;
            }

            if (countDigits % 2 == 0)
                result++;

        }

        return result;
    }
};

int main() {
    vector<int> arr = {12, 345, 2, 6, 7896};

    Solution obj;
    cout << obj.findNumbers(arr);

    return 0;
}
