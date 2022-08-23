#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *pNext;
};

struct List {
    Node *pHead;
    Node *pTail;
};


class LinkedList {
public:
    void printList(List l) {
        Node *p = l.pHead;
        while (p != NULL) {
            cout << p->data << endl;
            p = p->pNext;
        }
    }

    void deleteList(List &l) {
        Node *current = l.pHead;
        while(current != NULL) {
            Node *prev = current;
            current = current->pNext;
            delete prev;
            prev = NULL;
        }
    }

    Node * createNode(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->pNext = NULL;
        return newNode;
    }

    bool checkEmpty(Node *pHead) {
        if (pHead == NULL)
            return true;
        return false;
    }

    void addHead(List &l, Node *p) {
        if (checkEmpty(l.pHead)) {
            l.pHead = p;
        } else {
            p->pNext = l.pHead;
            l.pHead = p;
        }
    }

    void addTail(List &l, Node *p) {
        if (checkEmpty(l.pHead)) {
            l.pHead = p;
        } else {
            Node *temp = l.pHead;
            while (temp->pNext != NULL) {
                temp = temp->pNext;
            }
            temp->pNext = p;
        }
    }

    bool search(List &l, int x) {
        Node *current = l.pHead;
        while (current != NULL) {
            if (current->data == x)
                return true;
            current = current->pNext;
        }
        return false;
    }
}
