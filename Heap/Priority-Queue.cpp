#include <bits/stdc++.h>

using namespace std;

class MyPriorityQueue {
public:
    int H[50];
    int size = -1;

    int parent(int i) {
        return (i - 1)/2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void shiftUp(int i) {
        while (i > 0 && H[parent(i)] < H[i]) {
            swap(H[parent(i)], H[i]);
            i = parent(i);
        }
    }

    void shiftDown(int i) {
        int maxIndex = i;    
        int l = leftChild(i);
    
        if (l <= size && H[l] > H[maxIndex]) {
            maxIndex = l;
        }
    
        int r = rightChild(i);
    
        if (r <= size && H[r] > H[maxIndex]) {
            maxIndex = r;
        }
    
        if (i != maxIndex) {
            swap(H[i], H[maxIndex]);
            shiftDown(maxIndex);
        }
    }
 
    void insert(int p) {
        size = size + 1;
        H[size] = p;
        shiftUp(size);
    }
    

    int deleteMax() {
        int result = H[0];
        H[0] = H[size];
        size = size - 1;
        shiftDown(0);
        return result;
    }

    void changePriority(int i, int p) {
        int oldp = H[i];
        H[i] = p;
    
        if (p > oldp) {
            shiftUp(i);
        }
        else {
            shiftDown(i);
        }
    }

    int getMax() {
        return H[0];
    }

    void remove(int i) {
        H[i] = getMax() + 1;
        shiftUp(i);
        deleteMax();
    }

    void print(int i) {
        while (i <= size) {
            cout << H[i] << " ";
            i++;
        }
    
        cout << "\n";
    }
};

int main() {
    /*          45
              /   \
           31      14
          /  \    /  \
         13  20  7   11
        /  \
       12   7
    
    Array as: 45 31 14 13 20 7 11 12 7 */

    MyPriorityQueue obj;

    obj.insert(45);
    obj.insert(20);
    obj.insert(14);
    obj.insert(12);
    obj.insert(31);
    obj.insert(7);
    obj.insert(11);
    obj.insert(13);
    obj.insert(7);
 
    int i = 0;
 
    cout << "Priority Queue : ";
    obj.print(i);
 
    cout << "Node with maximum priority : " << obj.deleteMax() << "\n";
 
    cout << "Priority queue after extracting maximum : ";
    obj.print(i);

    obj.changePriority(2, 49);
    cout << "Priority queue after priority change : ";
    obj.print(i);
 
    obj.remove(3);
    cout << "Priority queue after removing the element : ";
    obj.print(i);

    return 0;
}