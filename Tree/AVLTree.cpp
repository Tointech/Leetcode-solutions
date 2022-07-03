#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    int height;
};

class MyAVLTree {
public:
    int height(Node *n) {
        if (n == nullptr) {
            return 0;
        }
        return n->height;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    Node *newNode(int key) {
        Node *node = new Node;
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1;
        return node;
    }

    Node *rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    int getBalance(Node *n) {
        if (n == nullptr) {
            return 0;
        }
        return height(n->left) - height(n->right);
    }

    Node *insertNode(Node *n, int key) {
        if (n == nullptr) {
            return newNode(key);
        }

        if (key < n->key) {
            n->left = insertNode(n->left, key);
        } else if (key > n->key) {
            n->right = insertNode(n->right, key);
        } else {
            return n;
        }

        n->height = 1 + max(height(n->left), height(n->right));
        int balance = getBalance(n);

        if (balance > 1 && key < n->left->key) {
            return rightRotate(n);
        }
        if (balance < -1 && key > n->right->key) {
            return leftRotate(n);
        }
        if (balance > 1 && key > n->left->key) {
            n->left = leftRotate(n->left);
            return rightRotate(n);
        }
        if (balance < -1 && key < n->right->key) {
            n->right = rightRotate(n->right);
            return leftRotate(n);
        }

        return n;
    }

    Node *minValueNode(Node *n) {
        Node *current = n;
        while(current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node *deleteNode(Node *root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr || root->right == nullptr) {
                Node *temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                    delete(temp);
                }
            } else {
                Node *temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }
        if (root == nullptr) {
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);
        
        if (balance > 1 && getBalance(root->left) >= 0) {
            return rightRotate(root);
        }

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
 
        if (balance < -1 && getBalance(root->right) <= 0) {
            return leftRotate(root);
        }
    
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    
        return root;
    }

    void preorderTraversal(Node *root) {
        if (root != nullptr) {
            cout << root->key << " ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }
};

int main() {
    Node *root = nullptr;

    MyAVLTree obj;
    root = obj.insertNode(root, 10);
    root = obj.insertNode(root, 20);
    root = obj.insertNode(root, 30);
    root = obj.insertNode(root, 40);
    root = obj.insertNode(root, 50);
    root = obj.insertNode(root, 25);

    cout << "Preorder traversal of the constructed AVL tree is:\n";
    obj.preorderTraversal(root);

    int n;
    cout << "\nInput number to delete: "; cin >> n;

    cout << "Preorder traversal of the constructed AVL tree after delete " << n << " is:\n";
    obj.deleteNode(root, n);
    obj.preorderTraversal(root);

    return 0;
}