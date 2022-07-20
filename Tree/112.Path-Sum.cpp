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
    bool isLeaf(TreeNode* node) {
        return (node->left == nullptr && node->right == nullptr);
    }
    
    bool browse(TreeNode *currentNode, int currentSum, int targetSum) {
        if (currentNode == nullptr) return false;
        
        currentSum += currentNode->val;
        
        if (isLeaf(currentNode)) {
            return currentSum == targetSum;
        }
        
        bool leftResult = browse(currentNode->left, currentSum, targetSum);
        bool rightResult = browse(currentNode->right, currentSum, targetSum);
        
        return (leftResult || rightResult);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return browse(root, 0, targetSum);
    }
};

int main() {
    return 0;
}