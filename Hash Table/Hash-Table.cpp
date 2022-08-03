#include <bits/stdc++.h>
using namespace std;
  
template <typename K, typename V>
class HashNode {
public:
    K key;
    V value;
  
    HashNode(K key, V value) {
        this->key = key;
        this->value = value;
    }
};
  
template <typename K, typename V>
class HashMap {
    HashNode<K, V>** arr;
    int capacity;
    int size;
    HashNode<K, V>* dummy;
  
public:
    HashMap() {
        capacity = 20;
        size = 0;
        arr = new HashNode<K, V>*[capacity];
  
        for (int i = 0; i < capacity; i++)
            arr[i] = nullptr;
  
        dummy = new HashNode<K, V>(-1, -1);
    }
    
    int hashFunction(K key) {
        return key % capacity;
    }
  
    void add(K key, V value) {
        HashNode<K, V>* temp = new HashNode<K, V>(key, value);
  
        int hashIndex = hashFunction(key);
  
        while (arr[hashIndex] != nullptr
               && arr[hashIndex]->key != key
               && arr[hashIndex]->key != -1) {
            hashIndex++;
            hashIndex %= capacity;
        }
  
        if (arr[hashIndex] == nullptr
            || arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = temp;
    }
  
    V remove(int key) {
        int hashIndex = hashFunction(key);
  
        while (arr[hashIndex] != nullptr) {
            if (arr[hashIndex]->key == key) {
                HashNode<K, V>* temp = arr[hashIndex];
  
                arr[hashIndex] = dummy;
  
                size--;
                return temp->value;
            }
            hashIndex++;
            hashIndex %= capacity;
        }
  
        return nullptr;
    }
  
    void output() {
        for (int i = 0; i < capacity; i++) {
            if (arr[i] != nullptr && arr[i]->key != -1)
                cout << "Key = " << arr[i]->key << "; Value = " << arr[i]->value << endl;
        }
    }
};
  
int main() {
    HashMap<int, int>* h = new HashMap<int, int>;
    h->add(1, 1);
    h->add(2, 2);
    h->add(2, 3);
    h->output();
  
    return 0;
}