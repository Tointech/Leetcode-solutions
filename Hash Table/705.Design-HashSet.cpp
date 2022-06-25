#include <bits/stdc++.h>

using namespace std;

class MyHashSet {
private:
    vector<int>* myBuckets;
public:
    MyHashSet() {
        myBuckets = new vector<int>;
    }

    void add(int key) {
        if(!contains(key))
            myBuckets->push_back(key);
    }

    void remove(int key) {
        for(int i = 0; i < myBuckets->size(); ++i){
            if((*myBuckets)[i] == key) {
                myBuckets->erase(myBuckets->begin() + i);
                break;
            }
        }
    }

    bool contains(int key) {
        for(int element : *myBuckets)
            if(element == key)
                return true;
        return false;
    }
};

int main() {
    int key = 3;
    MyHashSet* obj = new MyHashSet();
    obj->add(key);
    obj->remove(key);
    bool param_3 = obj->contains(key);
    return 0;
}
