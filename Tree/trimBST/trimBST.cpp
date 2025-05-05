#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return nullptr;
        //裁剪
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }
        //把孩子送去递归
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

int main() {
    // 构造如下BST:
    //        3
    //       / \
    //      0   4
    //       \
    //        2
    //       /
    //      1
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);

    int low = 1, high = 3;

    cout << "Before trimming (inorder): ";
    inorder(root);
    cout << endl;

    Solution sol;
    TreeNode* trimmed = sol.trimBST(root, low, high);

    cout << "After trimming (inorder): ";
    inorder(trimmed);
    cout << endl;

    return 0;
}
