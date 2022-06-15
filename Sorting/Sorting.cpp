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
    
    void merge(int a[], int p, int q, int r) {
        int n1 = q - p + 1;
        int n2 = r - q;

        int L[n1], M[n2];

        for (int i = 0; i < n1; i++)
            L[i] = a[p + i];
        for (int j = 0; j < n2; j++)
            M[j] = a[q + 1 + j];

        int i, j, k;
        i = 0;
        j = 0;
        k = p;

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

    void mergeSort(int a[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(a, l, m);
            mergeSort(a, m + 1, r);
            merge(a, l, m, r);
        }
    }

    void mergeSort(int a[], int n) {
        mergeSort(a, 0, n - 1);
    }

    void heapify(int a[], int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
    
        if (l < n && a[l] > a[largest])
            largest = l;
    
        if (r < n && a[r] > a[largest])
            largest = r;
    
        if (largest != i) {
            swap(a[i], a[largest]);
            heapify(a, n, largest);
        }
    }
    
    void heapSort(int a[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(a, n, i);

        for (int i = n - 1; i > 0; i--) {
            swap(a[0], a[i]);
            heapify(a, i, 0);
        }
    }

    int partition(int a[], int low, int high) {
        int pivot = a[(low+high)/2];
        int i = low;
        int j = high;
        while (i <= j) {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            if (i <= j) {
                swap(a[i], a[j]);
                i++; j--;
            }
        }
        return i;
    }

    void quickSort(int a[], int low, int high) {
        if (low < high) {
            int p = partition(a, low, high);
            quickSort(a, low, p-1);
            quickSort(a, p, high);
        }
    }

    void quickSort(int a[], int n) {
        quickSort(a, 0, n - 1);
    }

    void countingSort(int a[], int n) {
        int output[n];
        int max = a[0];
        int min = a[0];
    
        for(int i = 1; i < n; i++) {
            if(a[i] > max) {
                max = a[i];
            } else if(a[i] < min) {
                min = a[i];
            }
        }
    
        int size = max - min + 1;
        int countArray[size];
        for(int i = 0; i < size; i++) {
            countArray[i]=0;
        }
    
        for(int i = 0; i < n; i++) {
            countArray[a[i] - min]++;
        }

        for(int i = 1; i < size; i++) {
            countArray[i] += countArray[i - 1];
        }
    
        for(int i = 0; i < n; i++) {
            output[countArray[a[i] - min] - 1] = a[i];
            countArray[a[i] - min]--;
        }
    
        for(int i = 0; i < n; i++) {
            a[i] = output[i];
        }
    }

    int findMax(int a[], int n) {
        int max = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] > max) max = a[i];
        }
        return max;
    }

    void countingSort(int a[], int n, int exp) {
        int *result = new int [n + 1];
        int stor[10] = {0};
        
        for (int i = 0; i < n; i++) {
            stor[(a[i] / exp) % 10]++;
        }
    
        for (int i = 1; i < 10; i++) {
            stor[i] += stor[i - 1]; 
        }

        for (int i = n - 1; i >= 0; i--) {
            result[stor[(a[i] / exp) % 10] - 1] = a[i];
            stor[(a[i] / exp) % 10]--;        
        }

        for (int i = 0; i < n; i++) {
            a[i] = result[i];
        }

        delete[] result;
    }

    void radixSort(int a[], int n) {
        int len = findMax(a, n);
        for (int exp = 1; len / exp > 0; exp *= 10) {
            countingSort(a, n, exp);
        }
    }
};

int main() {
    int a[] = {3,4,1,5,8,9,5,3,1,6,7};
    int n = sizeof(a)/sizeof(a[0]);

    SortingMethod obj;
    obj.countingSort(a, n);
    obj.printArray(a, n);

    return 0;
}