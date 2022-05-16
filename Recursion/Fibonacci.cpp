#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Normal recursion
    int fibonacci(int n) {
        //cout << "Calculate F[" << n << "]\n"; 
        if (n <= 2) {
            return 1;
        }
        return fibonacci(n-1) + fibonacci(n-2);
    }
    
    // Recursion remember: reduce the number of function callbacks
    int fibonacci2(int n) {
        int F[100] = {0};
        if (F[n] != 0) {
            return F[n];
        }
        if (n <= 2) {
            F[1] = 1;
            F[2] = 1;
            return 1;
        }
        F[n] = fibonacci2(n-1) + fibonacci2(n-2);
        return F[n];
    }

    // Non-recursive method
    int fibonacci3(int n) {
        int F[100];
        // Bai toan co so
        F[1] = 1;
        F[2] = 1;
        for (int i = 3; i <= 10; i++) {
            // Inductive formula
            F[i] = F[i-1] + F[i-2];
        }; // Faster than call back function
        return F[n];
    }
};

int main() {
    Solution obj;
    cout << obj.fibonacci(10);
    return 0;
}