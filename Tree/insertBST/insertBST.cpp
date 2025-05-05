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
    TreeNode* insertBST(TreeNode* root, int val) {
        if (root == nullptr) { 
            TreeNode* result = new TreeNode(val);
            return result;
        }
        //return result插入了新节点
        if (root->val < val) root->right = insertBST(root->right, val);
        if (root->val > val) root->left =  insertBST(root->left, val);
        return root;
    }
};


// 中序遍历打印：结果应为升序
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    Solution sol;
    TreeNode* root = nullptr;

    // 插入节点
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values) {
        root = sol.insertBST(root, val);
    }

    cout << "Inorder traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}


