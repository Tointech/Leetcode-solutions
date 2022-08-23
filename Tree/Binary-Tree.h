struct TreeNode {
    int data;
    TreeNode *pLeft;
    TreeNode *pRight;
    TreeNode *parent;
    TreeNode(int data) {
        this->data = data;
        pLeft = pRight = parent = nullptr;
    }
};

struct BinaryTree {
    TreeNode *root;
    BinaryTree() {
        root = nullptr;
    }
};