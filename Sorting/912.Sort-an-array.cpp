#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> merge(vector<int>& arr1, vector<int>& arr2) {
        int length1 = arr1.size();
        int length2 = arr2.size();
        int newLength = length1 + length2;
        vector<int> temp;

        int idx1 = 0; int idx2 = 0;
        while (temp.size() < newLength) {
            if (idx1 < length1&& idx2 < length2) { // arr1 & arr2 are not empty
                if (arr1[idx1] <= arr2[idx2]) { // arr1 is smaller
                    temp.push_back(arr1[idx1]);
                    idx1++;
                } else { // arr2 is smaller
                    temp.push_back(arr2[idx2]);
                    idx2++;
                }
            } else { // arr1 or arr2 is empty
                if (idx1 < length1) { 
                    temp.push_back(arr1[idx1]);
                    idx1++;
                } else {
                    temp.push_back(arr2[idx2]);;
                    idx2++;
                }
            }
        }

        return temp;
    }

    vector<int> mergeSort(vector<int>& nums, int left, int right) {
        // Stop condition
        if (left == right) {
            vector<int> element;
            element.push_back(nums[left]);
            return element;
        }

        // Divide
        int mid = (left + right) / 2;
        vector<int> arr1 = mergeSort(nums, left, mid);
        vector<int> arr2 = mergeSort(nums, mid + 1, right);

        // Merge two sorted arrays
        vector<int> result = merge(arr1, arr2);
        return result;
    }

    vector<int> sortArray(vector<int>& nums) {
        int length = nums.size();
        return mergeSort(nums, 0, length-1);
    }

    void printArray(vector<int>& nums) {
        for (int n : nums) {
            cout << n << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> nums = {1, 5, 3, 2, 8, 7, 6, 4};


    Solution obj;
    vector<int> sortedArr = obj.sortArray(nums);
    obj.printArray(sortedArr);
    
    return 0;
}