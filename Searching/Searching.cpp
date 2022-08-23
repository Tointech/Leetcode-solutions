#include <bits/stdc++.h>

using namespace std;

class Searching {
public:
    int interpolationSearch(int a[], int n, int target) {    
        int lo = 0, hi = (n - 1);
    
        while (lo <= hi && target >= a[lo] && target <= a[hi]) {
            if (lo == hi) {
                if (a[lo] == target) return lo;
                return -1;
            }

            int pos = lo + (((double)(hi - lo) / (a[hi] - a[lo])) * (target - a[lo]));
    
            if (a[pos] == target)
                return pos;
    
            if (a[pos] < target)
                lo = pos + 1;
    
            else
                hi = pos - 1;
        }
        return -1;
    }

    int binarySearchIterative(int a[], int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
    
            if (a[mid] == target) {
                return mid;
            }

            if (a[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    int binarySearchRecursion(int a[], int left, int right, int target) {
        if (right >= left) {
            int mid = left + (right - left) / 2;
    
            if (a[mid] == target) {
                return mid;
            }

            if (a[mid] > target) {
                return binarySearchRecursion(a, left, mid - 1, target);
            }

            return binarySearchRecursion(a, mid + 1, right, target);
        }
    
        return -1;
    }
};

int main() {
    return 0;
}