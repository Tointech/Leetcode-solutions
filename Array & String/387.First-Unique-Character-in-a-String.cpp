#include <bits/stdc++.h>
#include <cstring>

using namespace std;

class Solution {
public:
    // using index by ascii number
    int firstUniqChar(string s) {
        int count[128] = {0};
        int n = s.length();

        for (int i = 0; i < n; i++) {
            count[s[i]]++; 
        }

        for (int i = 0; i < n; i++) {
            if (count[s[i]] == 1) {
                return i;
            } 
        }

        return -1;
    }
};

int main() {
    string s = "aabb";

    Solution obj;
    cout << obj.firstUniqChar(s);
    return 0;
}