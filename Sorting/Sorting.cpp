#include <bits/stdc++.h>

using namespace std;

class SortingMethod {
public:
    void printArray(int a[], int n) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void bubbleSort(int a[], int n) {
        for (int i = 0; i < n - 1; i++) {
            bool isSorted = true;
            for (int j = 0; j < n - 1; j++) {
                if (a[j] > a[j+1]) {
                    isSorted = false;
                    swap(a[j], a[j+1]);
                }
            }
            if (isSorted) {
                break;
            }
        }
    }

    void insertionSort(int a[], int n) {
        for (int i = 1; i < n; i++) {
            int value = a[i];
            int j = i - 1;
            while (value < a[j] && j >= 0) {
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = value;
        }
    }

    void selectionSort(int a[], int n) {
        for (int i = 0; i < n - 1; i++) {
            int value = a[i];
            int temp = a[i];
            int flag = i;
            for (int j = i + 1; j < n; j++) {
                if (temp > a[j]) {
                    temp = a[j];
                    flag = j;
                }
            }
            a[i] = temp;
            a[flag] = value;
        }
    }
};


int main() {
    int a[] = {3,4,1,5,8,9,5,3,1,6,7};
    int n = sizeof(a)/sizeof(a[0]);

    SortingMethod obj;
    obj.selectionSort(a, n);
    obj.printArray(a, n);

    return 0;
}