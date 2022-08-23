#include <bits/stdc++.h>
#define n 256 // n is the number of characters in the input alphabet

using namespace std;

class StringMatching {
public:
    // Naive String-matching
    void bruteForce(char* origin, char* str) {
        int M = strlen(str);
        int N = strlen(origin);

        for (int i = 0; i <= N - M; i++) {
            int j;
            for (j = 0; j < M; j++) {
                if (origin[i+j] != str[j]) break;
            }

            if (j == M) {
                cout << "String found at index " << i << endl;
            }
        }
    }

    // Rabin-Karp
    void rabinKarp(char origin[], char str[]) {
        int M = strlen(str);
        int N = strlen(origin);
        int i, j;
        int p = 0;
        int t = 0;
        int h = 1;
    
        for (i = 0; i < M - 1; i++) {
            h = (h * n) % INT_MAX;
        }

        for (i = 0; i < M; i++) {
            p = (n * p + str[i]) % INT_MAX;
            t = (n * t + origin[i]) % INT_MAX;
        }
    
        for (i = 0; i <= N - M; i++) {
            if ( p == t ) {  
                for (j = 0; j < M; j++) {
                    if (origin[i+j] != str[j]) {
                        break;
                    }     
                }            
                if (j == M)
                    cout<<"String found at index "<< i <<endl;
            }

            if ( i < N-M ) {
                t = (n*(t - origin[i]*h) + origin[i+M])%INT_MAX;
                if (t < 0)
                t = (t + INT_MAX);
            }
        }
    }

    //Knuth-Morris-Pratt
    void computeLPSArray(char* str, int M, int* lps) {
        int len = 0;
        lps[0] = 0;
    
        int i = 1;
        while (i < M) {
            if (str[i] == str[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    void knuthMorrisPratt(char* origin, char* str) {
        int M = strlen(str);
        int N = strlen(origin);
        int lps[M];
    
        computeLPSArray(str, M, lps);
    
        int i = 0;
        int j = 0;
        while (i < N) {
            if (str[j] == origin[i]) {
                j++;
                i++;
            }
    
            if (j == M) {
                cout<<"String found at index "<< i - j <<endl;
                j = lps[j - 1];
            }
    
            else if (i < N && str[j] != origin[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i = i + 1;
                }
            }
        }
    }
};

int main() {
    char origin[] = "AABAACAADAABAAABAA";
    char str[] = "AABA";

    StringMatching obj;
    obj.knuthMorrisPratt(origin, str);

    return 0;
}