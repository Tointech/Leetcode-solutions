#include <bits/stdc++.h>

using namespace std;

// Linear Probing
class MyHashSetA {
private:
    vector<list<int>> myBuckets;
    int size;
public:
    MyHashSetA() {
        size = 100;
        myBuckets.resize(size);
    }

    int hashFunction(int key) {
        return key%size;
    }

    list<int> :: iterator search(int key) {
        int index = hashFunction(key);
        return find(myBuckets[index].begin(), myBuckets[index].end(), key);
    }

    void add(int key) {
        if(contains(key)) return;
        int index = hashFunction(key);
        myBuckets[index].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int index = hashFunction(key);
        myBuckets[index].erase(search(key));
    }
    
    bool contains(int key) {
        int index = hashFunction(key);
        return search(key) != myBuckets[index].end();
    }
};

// Chaining
class Node {
public:
    int data;
    Node *next;
};

class MyHashSetB {
public:
    Node *head;

    MyHashSetB() {
        head = nullptr;
    }

    void output() {
        Node *temp = head;
        while(temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void add(int key) {
        if (contains(key)) return;
        Node *newNode = new Node();
        newNode->data = key;
        Node *temp = head;
        if (temp == nullptr) {
            head = newNode;
            return;
        }
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void remove(int key) {
        // if(!contains(key)) return;
        if (head == nullptr) {
            return;
        }
        if (head->data == key) {
            head = head->next;
        }

        Node *temp = head;
        Node *prev = nullptr;
        
        while (temp != nullptr) {
            if (temp->data == key) {
                prev->next = temp->next;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    bool contains(int key) {
        if (head == nullptr) {
            return false;
        }
        Node *temp = head;
        while(temp != nullptr) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

int main() {
    MyHashSetA *mySet = new MyHashSetA();
    mySet->add(1);
    mySet->add(2);
    mySet->add(1);
    return 0;
}
