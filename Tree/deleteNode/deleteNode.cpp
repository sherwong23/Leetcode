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
    TreeNode* deleteNode(TreeNode* root, int key){
    if (root == nullptr) return root;
    if (root->val == key) {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        //返回的应该是root,但没了,返回null
        else if (root->left == nullptr && root->right != nullptr) {
            auto retNode = root->right;
            delete root;
            return retNode;
        }
        else if (root->left != nullptr && root->right == nullptr) {
            auto retNode = root->left;
            delete root;
            return retNode;
        }
        else if (root->left != nullptr && root->right != nullptr) {
            //将左节点移植到右节点的最左节点的左子
            TreeNode* cul = root->right;
            while (cul->left != nullptr){
                cul = cul->left;
            }
            cul->left = root->left;
            auto tmp = root;
            root = tmp->right;
            delete tmp;
            return root;
        }
    }
    if (root->val < key) root->right = deleteNode(root->right, key);
    if (root->val > key) root->left = deleteNode(root->left, key);
    return root;
    }
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // 手动建树：      5
    //              /   \
    //             3     6
    //            / \     \
    //           2   4     7
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "Before deletion (inorder): ";
    inorder(root);
    cout << endl;

    Solution sol;
    root = sol.deleteNode(root, 3); // 删除节点 3

    cout << "After deletion (inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
