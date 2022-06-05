#include <bits/stdc++.h>

using namespace std;

struct Stack {
    int *data;
    int top;
    int capacity;
};

class StackArray {
public:
    void init(Stack* &s, int capacity) {
        s->top = -1;
        s->capacity = capacity;
        s->data = new int[s->capacity];
        cout << "Init stack success!\n";
    }

    bool isFull(Stack* s) {
        if (s->top >= s->capacity - 1) {
            return true;
        } else {
            return false;
        }
    }

    bool isEmpty(Stack* s) {
        if (s->top < 0) {
            return true;
        } else {
            return false;
        }
    }

    void push(Stack* &s, int value) {
        if (isFull(s)) {
            cout << "Stack Overflow!\n";
            return;
        } else {
            s->top++;
            s->data[s->top] = value;
            cout << s->data[s->top] << " pushed into stack!\n";
        }
    }

    int pop(Stack* &s) {
        if (isEmpty(s)) {
            cout << "Stack Underflow!\n";
            return 0;
        } else {
            int tailValue = s->data[s->top];
            s->data[s->top] = 0;
            s->top--;
            cout << tailValue << " popped from stack!\n";
            return tailValue;
        }
    }

    void clear(Stack* &s) {
        s->top = -1;
        s->capacity = 0;
        delete[] s->data;
        s->data = nullptr;
        cout << "Clear the stack success!\n";
    }

    int size(Stack* s) {
        return s->top++;
    }
};

struct Queue {
    int *data;
    int head;
    int tail;
    int capacity;
};

class QueueArray {
public:
    void init(Queue* &q, int capacity) {
        q->head = q->tail = -1;
        q->capacity = capacity;
        q->data = new int[q->capacity];
        cout << "Init queue success!\n";
    }

    bool isFull(Queue* q) {
        if (q->tail >= q->capacity - 1) {
            return true;
        } else {
            return false;
        }
    }

    bool isEmpty(Queue* q) {
        if (q->head == -1 || q->head > q->tail) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(Queue* &q, int value) {
        if (isFull(q)) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (q->head == -1) {
            q->head = 0;
        }
        q->tail++;
        q->data[q->tail] = value;
        cout << q->data[q->tail] << " enqueued into queue!\n";
    }
    
    int dequeue(Queue* &q) {
        if (isEmpty(q)) {
            cout << "Queue Underflow!\n";
            return 0;
        }
        int headValue = q->data[q->head];
        q->data[q->head] = 0;
        q->head++;
        cout << headValue << " dequeued from queue!\n";
        return headValue;
    }

    void clear(Queue* &q) {
        q->head = q->tail = -1;
        q->capacity = 0;
        delete[] q->data;
        q->data = nullptr;
        cout << "Clear the queue success!\n";
    }

    int size(Queue* q) {
        if (q->head == -1 && q->tail == -1) {
            return 0;
        } else {
            return ((q->tail - q->head) + 1);
        }
    }
};

int main() {
    // Implement stack with array
    StackArray obj1;
    Stack *s = new Stack;

    int n1;
    cout << "Input a size of stack: "; cin >> n1;
    obj1.init(s, n1);

    // Implement queue with array
    QueueArray obj2;
    Queue *q = new Queue;

    int n2;
    cout << "Input a size of queue: "; cin >> n2;
    obj2.init(q, n2);

    return 0;
}