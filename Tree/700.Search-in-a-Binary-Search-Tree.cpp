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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }
        if (val < root->val) {
            return searchBST(root->left, val);
        } else if (val > root->val) {
            return searchBST(root->right, val);
        } else {
            return root;
        }
    }
};

int main() {
    return 0;
}