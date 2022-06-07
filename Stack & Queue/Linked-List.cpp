#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Stack {
    Node *head;
    int capacity;
};

class StackLinkedList {
public:
    void init(Stack* &s) {
        s->capacity = 0;
        s->head = nullptr;
        cout << "Init stack success!\n";
    }

    bool isEmpty(Stack* s) {
        if (s->capacity <= 0) {
            return true;
        } else {
            return false;
        }
    }

    Node * createNode(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }

    void push(Stack* &s, int value) {
        Node *newNode = createNode(value);
        if (isEmpty(s)) {
            s->head = newNode;
        } else {
            newNode->next = s->head;
            s->head = newNode;
        }
        s->capacity++;
        cout << value << " pushed into stack!\n";
    }

    int pop(Stack* &s) {
        if (isEmpty(s)) {
            cout << "Stack Underflow!\n";
            return 0;
        } else {
            Node *newNode = s->head;
            s->head = s->head->next;
            newNode->next = nullptr;
            s->capacity--;
            cout << newNode->data << " popped from stack!\n";
            return newNode->data;
        }
    }

    void clear(Stack* &s) {
        if (isEmpty(s)) {
            return;
        }
        Node *prev = new Node;
        Node *head = s->head;
        while(head != nullptr) {
            prev = head;
            head = head->next;
            delete prev;
            prev = nullptr;
            s->capacity--;
        }
        s->head = nullptr;
        head = nullptr;
        cout << "Clear the stack success!\n";
    }

    void inputStack(Stack* &s) {
        int n, value;
        cout << "Input number of elements to add: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Input value of element " << i + 1 << ": ";
            cin >> value;
            push(s, value);
        }
    }

    void outputStack(Stack* s) {
        if (isEmpty(s)) {
            cout << "Stack is empty!\n";
        } else {
            Node *temp = s->head;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

struct Queue {
    Node *head;
    Node *tail;
    int capacity;
};

class QueueLinkedList {
public:
    void init(Queue* &q) {
        q->capacity = 0;
        q->head = q->tail = nullptr;
        cout << "Init queue success!\n";
    }

    Node * createNode(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }

    bool isEmpty(Queue* q) {
        if (q->capacity == 0) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(Queue* &q, int value) {
        Node *newNode = createNode(value);
        if (isEmpty(q)) {
            q->head = q->tail = newNode;
        } else {
            q->tail->next = newNode;
            q->tail = newNode;
        }
        q->capacity++;
        cout << value << " pushed into queue!\n";
    }
    
    int dequeue(Queue* &q) {
        if (isEmpty(q)) {
            cout << "Queue underflow!\n";
            return 0;
        } else {
            Node *newNode = q->head;
            q->head = q->head->next;
            newNode->next = NULL;
            q->capacity--;
            cout << newNode->data << " popped from queue!\n";
            return newNode->data;
        }
    }

    void clear(Queue* &q) {
        if (isEmpty(q)) {
            return;
        }
        Node *prev = new Node;
        Node *head = q->head;
        while(head != NULL) {
            prev = head;
            head = head->next;
            prev->next = NULL;
            delete prev;
            q->capacity--;
        }
        q->head = q->tail = NULL;
        cout << "Clear queue success!\n";
    }

    void inputQueue(Queue* &q) {
        int n, value;
        cout << "Input number of elements to add: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Input value of element " << i + 1 << ": ";
            cin >> value;
            enqueue(q, value);
        }
    }

    void outputQueue(Queue* &q) {
        if (isEmpty(q)) {
            cout << "Queue is empty!\n";
        } else {
            Node *temp = q->head;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    // Implement stack with linked list
    StackLinkedList obj1;
    Stack *s = new Stack;
    obj1.init(s);

    // Implement queue with linked list
    QueueLinkedList obj2;
    Queue *q = new Queue;
    obj2.init(q);

    return 0;
}