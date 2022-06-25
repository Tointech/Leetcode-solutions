#include <bits/stdc++.h>

#define MAX 100

using namespace std;

class BaseFile {
public:
    void readFile(int a[][MAX], int &n, int nInline[]) {
        ifstream fIn;
        fIn.open("./base_data.txt", ios::in);
        if (fIn.is_open()) {
            int base;
            string s;
            n = 0;
            fIn >> n;
            for (int i = 0; i < n; i++) {
                fIn >> dec >> nInline[i] >> base;
                switch (base) {
                    case 16:
                        for (int j = 0; j < nInline[i]; j++) {
                            fIn >> hex >> a[i][j];
                        }
                        break;
                    case 10:
                        for (int j = 0; j < nInline[i]; j++) {
                            fIn >> a[i][j];
                        }
                        break;
                    case 8:
                        for (int j = 0; j < nInline[i]; j++) {
                            fIn >> oct >> a[i][j];                        
                        }
                        break;
                    case 2:
                        for (int j = 0; j < nInline[i]; j++) {
                            fIn >> s;
                            a[i][j] = stoi(s, nullptr, 2);
                        }
                        break;
                }
            }
        }
        fIn.close();
    }
};

int main() {

    return 0;
}