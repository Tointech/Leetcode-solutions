#include <bits/stdc++.h>

using namespace std;

// Min-heap
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
        while (i > 0 && H[parent(i)] > H[i]) {
            swap(H[parent(i)], H[i]);
            i = parent(i);
        }
    }

    void shiftDown(int i) {
        int minIndex = i;    
        int l = leftChild(i);
    
        if (l <= size && H[l] < H[minIndex]) {
            minIndex = l;
        }
    
        int r = rightChild(i);
    
        if (r <= size && H[r] < H[minIndex]) {
            minIndex = r;
        }
    
        if (i != minIndex) {
            swap(H[i], H[minIndex]);
            shiftDown(minIndex);
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
    
        if (p < oldp)
            shiftUp(i);
        else
            shiftDown(i);
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
    /*          7
              /   \
           13      11
          /  \    /  \
         14  31  20   12
        /  
       45   
    
    Array as: 7 13 11 14 31 20 12 45 */

    MyPriorityQueue obj;

    obj.insert(45);
    obj.insert(20);
    obj.insert(14);
    obj.insert(12);
    obj.insert(31);
    obj.insert(7);
    obj.insert(11);
    obj.insert(13);
 
    int i = 0;
 
    cout << "Priority Queue : ";
    obj.print(i);
 
    cout << "Node with 1st priority : " << obj.deleteMax() << "\n";
 
    cout << "Priority queue after extracting 1st priority: ";
    obj.print(i);

    obj.changePriority(2, 1);
    cout << "Priority queue after priority change : ";
    obj.print(i);
 
    obj.remove(3);
    cout << "Priority queue after removing the element : ";
    obj.print(i);

    return 0;
}