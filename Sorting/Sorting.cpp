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
    
    // Merge two sub arrays L and M into arr
    void merge(int a[], int p, int q, int r) {
    
        // Create L ← A[p..q] and M ← A[q+1..r]
        int n1 = q - p + 1;
        int n2 = r - q;

        int L[n1], M[n2];

        for (int i = 0; i < n1; i++)
            L[i] = a[p + i];
        for (int j = 0; j < n2; j++)
            M[j] = a[q + 1 + j];

        // Maintain current index of sub-arrays and main array
        int i, j, k;
        i = 0;
        j = 0;
        k = p;

        // Until we reach either end of either L or M, pick larger among
        // elements L and M and place them in the correct position at A[p..r]
        while (i < n1 && j < n2) {
            if (L[i] <= M[j]) {
                a[k] = L[i];
                i++;
                } else {
                a[k] = M[j];
                j++;
            }
            k++;
        }

        // When we run out of elements in either L or M,
        // pick up the remaining elements and put in A[p..r]
        while (i < n1) {
            a[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            a[k] = M[j];
            j++;
            k++;
        }
    }

    // Divide the array into two sub arrays, sort them and merge them
    void mergeSort(int a[], int l, int r) {
        if (l < r) {
            // m is the point where the array is divided into two subarrays
            int m = l + (r - l) / 2;

            mergeSort(a, l, m);
            mergeSort(a, m + 1, r);

            // Merge the sorted subarrays
            merge(a, l, m, r);
        }
    }

    void mergeSort(int a[], int n) {
        mergeSort(a, 0, n - 1);
    }

    int partition(int a[], int l, int r, int key) { // return pivot value
        int iL = l; int iR = r;
        while(iL <= iR) {
            while(a[iL] < key) {
                iL++;
            }
            while(a[iR] > key) {
                iR--;
            }
            if (iL <= iR) {
                swap(a[iL], a[iR]);
                iL++;
                iR--;
            }
        }
        return iL;
    }

    void quickSort(int a[], int l, int r) {
        if (l >= r) {
            return;
        }

        int key = a[(l+r)/2];

        int k = partition(a, l, r, key);

        quickSort(a, l, k-1);
        quickSort(a, k, r);
    }

    void quickSort(int a[], int n) {
        quickSort(a, 0, n-1);
    }
};

int main() {
    int a[] = {3,4,1,5,8,9,5,3,1,6,7};
    int n = sizeof(a)/sizeof(a[0]);

    SortingMethod obj;
    obj.quickSort(a, n);
    obj.printArray(a, n);

    return 0;
}