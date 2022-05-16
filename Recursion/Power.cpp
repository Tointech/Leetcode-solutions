#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Normal recursion
    int power(int a, unsigned int n) {
        if (n == 0) {
            return 1;
        }
        if (a == 0) {
            return 0;
        }
        return a * power(a, n-1);
    }
    // Time Complexity: O(n); Space Complexity: 0(1)

    // Divide and conquer
    int power2(int a, unsigned int n) {
        if (n == 0) {
            return 1;
        } else if (n % 2 == 0) {
            return power2(a, n/2) * power2(a, n/2);
        } else {
            return a * power2(a,(n-1)/2) * power2(a,(n-1)/2);
        }
    }
    // Time Complexity: O(n); Space Complexity: 0(1)

    // Optimized by calculating power(a, n/2) only once and storing it
    int power3(int a, unsigned int n) {
        int temp;
        if (n == 0) {
            return 1;
        }
        temp = power3(a, n/2);
        if (n % 2 == 0) {
            return temp * temp;
        } else {
            return a * temp * temp;
        }
    }
    // Time Complexity: O(logn); Space Complexity: 0(1)

    // Non-recursive method
    int power4(int a, unsigned int n) {
        int result = 1;
        while(n > 0) {
            if (n % 2 == 0) {
                a *= a;
                n /= 2;
            } else {
                result *= a;
                n -= 1;
            }
        }
        return result;
    }
    // Time Complexity: O(logn); Space Complexity: 0(1)
};

int main() {
    Solution obj;
    cout << obj.power4(2, 2);
    return 0;
}