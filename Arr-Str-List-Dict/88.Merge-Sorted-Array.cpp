#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void insert(vector<int>& a, int value, int position) {
        bool isSequent = true;
        int flag = 0;

        for (int i = 0; i < position; i++) {
            if (a[i] > value) {
                isSequent = false;
                for (int j = position - 1; j >= i; j--) {
                    a[j+1] = a[j];
                } 
                a[i] = value;
                break;
            }
        }

        if (isSequent)
            a[position] = value;
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int num : nums2) {
            insert(nums1, num, m);
            m++;
        }
    } 
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    Solution obj;
    obj.merge(nums1, m, nums2, n);

    for (int i = 0; i < m + n; i++) {
        cout << nums1[i] << " ";
    }

    return 0;
}