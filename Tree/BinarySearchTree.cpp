#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int val) {
        this->val = val;
        left = right = nullptr;
    }
};

struct BinarySearchTree {
    Node *root;
    BinarySearchTree() {
        root = nullptr;
    }
};

class MyBinaryTree {
public:
    void insertIntoBST(BinarySearchTree *tree, int key) {
        Node *newNode = new Node(key);

        if (tree->root == nullptr) {
            tree->root = newNode;
            return;
        }

        Node *temp = tree->root;
        while(true) {
            if (key > temp->val) {
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    break;
                }
                temp = temp->right;
            } else {
                if (temp->left == nullptr) {
                    temp->left = newNode;
                    break;
                }
                temp = temp->left;
            }
        }
    }

    void inorderTraversal(Node *root) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }

    void printBST(BinarySearchTree *tree) {
        Node *temp = tree->root;
        inorderTraversal(temp);
        cout << endl;
    }

    int heightBST(Node *root) {
        if (root == nullptr) {
            return 0;
        } else {
            int lDepth = heightBST(root->left);
            int rDepth = heightBST(root->right);

            if (lDepth > rDepth) {
                return lDepth + 1;
            } else {
                return rDepth + 1;
            }
        }
    }

    void printLeafNodes(Node *root) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            cout << root->val << " ";
            return;
        }

        if (root->left != nullptr) {
            printLeafNodes(root->left);
        }

        if (root->right != nullptr) {
            printLeafNodes(root->right);
        }
    }

    void printNodeInGivenLevel(Node *root, int level) {
        if (root == nullptr) {
            return;
        }
        if (level == 1) {
            cout << root->val << " ";
        } else if (level > 1) {
            printNodeInGivenLevel(root->left, level - 1);
            printNodeInGivenLevel(root->right, level - 1);
        }
    }

    void printNodeInLevelOrder(BinarySearchTree *tree) {
        int h = heightBST(tree->root);
        for (int i = 1; i <= h; i++) {
            cout << "Line " << i << " : ";
            printNodeInGivenLevel(tree->root, i);
            cout << "\n";
        }
    }

    Node * minValueNode(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node *current = root;
        // Loop down to find the leftmost leaf
        while (current != nullptr && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node * maxValueNode(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node *current = root;
        // Loop down to find the rightmost leaf
        while (current != nullptr && current->right != nullptr) {
            current = current->right;
        }
        return current;
    }

    Node * deleteNode(Node *root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                Node *temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            Node *temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }

    Node * deleteOddValueNode(Node *root) {
        if (root == nullptr) {
            return root;
        }

        if (root->val % 2 != 0) {
            root = deleteNode(root, root->val);
            root = deleteOddValueNode(root);
        } else {
            root->left = deleteOddValueNode(root->left);
            root->right = deleteOddValueNode(root->right);
        }

        return root;
    }

    void printMinMaxFormat(BinarySearchTree *tree) {
        BinarySearchTree *temp = tree;
        while (temp->root != nullptr) {
            Node *min = minValueNode(temp->root);
            Node *max = maxValueNode(temp->root);

            cout << "Min - Max : " << max->val << " - " << min->val << endl;

            temp->root = deleteNode(temp->root, min->val);
            temp->root = deleteNode(temp->root, max->val);
        }
    }

    int nodeCount(Node *root) {
        if (root == nullptr) {
            return 0;
        } else {
            return nodeCount(root->left) + nodeCount(root->right) + 1;
        }
    }

    Node * emptyBST(Node *root) {
        Node *temp;
        if (root != nullptr) {
            emptyBST(root->left);
            emptyBST(root->right);
            cout << "Released node: " << root->val << endl;
            temp = root;
            delete temp;
        }
        return root;
    }

    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key) {
        if (root == nullptr) {
            return;
        }

        if (root->val == key) {
            if (root->left != nullptr) {
                Node *temp = root->left;
                while (temp->right != nullptr) {
                    temp = temp->right;
                }
                pre = temp;
            }

            if (root->right != nullptr) {
                Node *temp = root->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                suc = temp;
            }
        }

        if (root->val > key) {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        } else {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
    }

};

int main() {
    MyBinaryTree obj;
    BinarySearchTree *tree = new BinarySearchTree;

    obj.insertIntoBST(tree, 55);
    obj.insertIntoBST(tree, 31);
    obj.insertIntoBST(tree, 23);
    obj.insertIntoBST(tree, 42);
    obj.insertIntoBST(tree, 79);
    obj.insertIntoBST(tree, 62);
    obj.insertIntoBST(tree, 85);


    obj.printBST(tree);
    obj.printNodeInLevelOrder(tree);
    obj.printLeafNodes(tree->root);

    Node *min = obj.minValueNode(tree->root);
    Node *max = obj.maxValueNode(tree->root);
    cout << endl;
    cout << "Min value of node: " << min->val << endl;
    cout << "Max value of node: " << max->val << endl;
    cout << "Node count: " << obj.nodeCount(tree->root) << endl;


    tree->root = obj.deleteNode(tree->root, 55);
    obj.printBST(tree);
    obj.printNodeInLevelOrder(tree);

    // tree->root = obj.deleteOddValueNode(tree->root);
    // obj.printBST(tree);
    // obj.printNodeInLevelOrder(tree);

    // obj.printMinMaxFormat(tree);

    Node *pre = nullptr;
    Node *suc = nullptr;
    int key = 50;
    obj.findPreSuc(tree->root, pre, suc, key);
    if (pre != nullptr) {
        cout << "Predecessor is: " << pre->val << endl; 
    } else {
        cout << "Have no predecessor!\n";
    }
    if (suc != nullptr) {
        cout << "Successor is: " << suc->val << endl; 
    } else {
        cout << "Have no successor!\n";
    }

    obj.emptyBST(tree->root);

    cout << "Done!\n";
    return 0;
}