#include <bits/stdc++.h>

using namespace std;

// Min heap implement
class MyHeap {
public:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE + 1];
    int size;

    MyHeap() {
        size = 0;
    }

    bool isEmpty() {
        return size <= 0;
    }

    // Return root value
    int peek() {
        if(isEmpty()) {
            return -1;
        }
        return arr[1];
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void add(int v) {
        size++;
        arr[size] = v;

        // Heapify up
        int curIndex = size;
        int parentIndex = curIndex / 2;

        while(parentIndex != 0 && arr[parentIndex] > arr[curIndex]) {
            swap(arr[parentIndex], arr[curIndex]);
            curIndex = parentIndex;
            parentIndex = curIndex / 2;
        }
    }

    void heapifyDown(int curIndex) {        
        while (2 * curIndex <= size) {
            int leftChildIndex = 2 * curIndex;
            int rightChildIndex = leftChildIndex + 1;

            int smallerChildIndex = leftChildIndex;
            if (rightChildIndex <= size && arr[rightChildIndex] < arr[leftChildIndex]) {
                smallerChildIndex = rightChildIndex;
            }

            if (arr[curIndex] > arr[smallerChildIndex]) {
                swap(arr[curIndex], arr[smallerChildIndex]);
                curIndex = smallerChildIndex;
            } else {
                break;
            }
        }
    }

    // Return and delete root
    int poll() {
        if(isEmpty()) {
            return -1;
        }   
        int root = arr[1];

        arr[1] = arr[size];
        size--;

        heapifyDown(1);

        return root;
    }

    void remove(int v) {
        int curIndex = -1;
        for (int i = 1; i <= size; i++) {
            if (arr[i] == v) {
                curIndex = i;
                break;
            }
        }

        if (curIndex == -1) {
            return;
        }

        arr[curIndex] = arr[size];
        size--;

        heapifyDown(curIndex);
    }
};

int main() {
    MyHeap *myHeap = new MyHeap();
    myHeap->add(10);
    myHeap->add(5);
    myHeap->add(1);
    myHeap->add(6);

    cout << myHeap->peek() << endl;
    myHeap->remove(1);
    cout << myHeap->peek() << endl;
    myHeap->remove(6);

    while(!myHeap->isEmpty()) {
        cout << myHeap->poll() << " ";
    }

    return 0;
}