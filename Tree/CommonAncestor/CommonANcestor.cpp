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
    TreeNode* CommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //自己有归到自己(也处理了上下关系)
    if (root == q || root == p || root == NULL) return root;
    TreeNode* left = CommonAncestor(root->left, p, q);
    TreeNode* right = CommonAncestor(root->right, p, q);

    //两边都有归到自身,一边没有归到另一边
    if (left != nullptr && right != nullptr) return root;
    else if (left != nullptr && right == nullptr) return left;
    else if (left == nullptr && right != nullptr) return right;
    else {
        return nullptr;
    }
    }
};

int main() {
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode* p = root->left;              // Node 5
    TreeNode* q = root->left->right->right; // Node 4

    Solution sol;
    TreeNode* ancestor = sol.CommonAncestor(root, p, q);
    if (ancestor)
        cout << "Lowest Common Ancestor: " << ancestor->val << endl;
    else
        cout << "No common ancestor found." << endl;
    return 0;
}

