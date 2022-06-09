#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinarySearchTree {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *newNode = new TreeNode(val);

        if (root == nullptr) {
            root = newNode;
            return root;
        }

        TreeNode *temp = root;
        while(true) {
            if (val > temp->val) {
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

        return root;
    }
};

int main() {
    return 0;
}