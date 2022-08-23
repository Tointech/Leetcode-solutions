#include <bits/stdc++.h>

using namespace std;

class BinaryFile {
public:
    void readFile(int a[], int &n) {
        ifstream fIn;
        fIn.open("./input_file.bin", ios::in | ios::binary);
        
        if (fIn.is_open()) {
            fIn.read((char *)&n, sizeof(n));
            for (int i = 0; i < n; i++) {
                fIn.read((char *)&a[i], sizeof(a[i]));
            }
            cout << "Read success!\n";
        }

        fIn.close();
    }

    void writeFile(int a[], int n) {
        ofstream fOut;
        fOut.open("./output_file.bin", ios::out | ios::binary);
        
        if (fOut.is_open()) {
            fOut.write((char*)&n, sizeof(n))
            for (int i = 0; i < n; i++) {
                fOut.write((char*)&a[i], sizeof(a[i]));
            }
            cout << "Write success!\n";
        }

        fOut.close();
    }
};

int main() {

    return 0;
}