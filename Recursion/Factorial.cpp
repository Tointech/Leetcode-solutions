#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int factorial(int n) {
        if (n == 0) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }
};

int main() {
    Solution obj;
    cout << obj.factorial(3);
    return 0;
}