#include <bits/stdc++.h>

using namespace std;

class TxtFile {
public:
    void readFile(int a[], int &n) {
        ifstream fIn;
        fIn.open("./input_file.txt", ios::in);
        if (fIn.is_open()) {
            fIn >> n;
            for (int i = 0; i < n; i++) {
                fIn >> a[i];
                fIn.ignore(1);
                // fIn.ignore(100, ':');
            }
        }    
        
        fIn.close();
    }

    void writeFile(int a[], int n) {
        ofstream fOut;
        fOut.open("./output_file.txt", ios::out);
        
        if (fOut.is_open()) {
            fOut << n << endl;
            for (int i = 0; i < n; i++) {
                fOut << a[i] << " ";
            }
            cout << "Write success!\n";
        }

        fOut.close();
    }
};

int main() {

    return 0;
}