#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(nullptr) {}
};

class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    };

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }

    void traversal2(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal2(cur->left, vec);
        vec.push_back(cur->val);
        traversal2(cur->right, vec);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal2(root, result);
        return result;
    }

    void traversal3(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal3(cur->left, vec);
        traversal3(cur->right, vec);
        vec.push_back(cur->val);
    }

    vector<int> postTraversal(TreeNode* root) {
        vector<int> result;
        traversal3(root, result);
        return result;
    }
};

void printVec(const vector<int>& vec) {
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    vector<int> result;
    printVec(sol.preorderTraversal(root));
    printVec(sol.inorderTraversal(root));
    printVec(sol.postTraversal(root));
    
    return 0;
}


