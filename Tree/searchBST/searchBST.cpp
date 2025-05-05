#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) return root;
        if (root->val > val) return searchBST(root->left, val);
        if (root->val < val) return searchBST(root->right, val);
        return nullptr;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);
    TreeNode* result = sol.searchBST(root, 1);
    cout << result->left->val << endl;
    return 0;
}
