#include <bits/stdc++.h>

using namespace std;

struct Node {
public:
    int key, val;
    Node* next;
    Node(int k, int v, Node* n) {
        key = k;
        val = v;
        next = n;
    }
};

class MyHashMap {
public:
    const static int SIZE = 19997;
    Node* data[SIZE] = {};

    int hash(int key) {
        return key % SIZE;
    }

    void put(int key, int val) {
        remove(key);
        int h = hash(key);
        Node* node = new Node(key, val, data[h]);
        data[h] = node;
    }    

    int get(int key) {
        int h = hash(key);
        Node* node = data[h];
        for (; node != nullptr; node = node->next)
            if (node->key == key) return node->val;
        return -1;
    }    

    void remove(int key) {
        int h = hash(key);
        Node* node = data[h];
        if (node == nullptr) return;
        if (node->key == key) {
            data[h] = node->next;
            delete node;
        } else for (; node->next != nullptr; node = node->next)
            if (node->next->key == key) {
                Node* temp = node->next;
                node->next = temp->next;
                delete temp;
                return;
            }
    }
};

int main() {
    return 0;
}