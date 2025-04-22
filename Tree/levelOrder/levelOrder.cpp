#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

void printVec(vector<vector<int>> result) {
    for (vector<int> nums : result) {
        for (int i : nums) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
    public:
        //迭代
        vector<vector<int>> levelOrder(TreeNode* root) {
            queue<TreeNode*> que;
            if (root) que.push(root);
            vector<vector<int>> result;
            while (!que.empty()) {
                vector<int> nums;
                int size = que.size();
                for (int i =0; i < size; i++) {
                    TreeNode* cur = que.front();
                    que.pop();
                    nums.push_back(cur->val);
                    if (cur->left) que.push(cur->left);
                    if (cur->right) que.push(cur->right);
                }
                result.push_back(nums);
            }
            return result;
        }
        //递归
        vector<vector<int>> levelOrder2(TreeNode* root) {
            vector<vector<int>> result;
            int dept = 0;
            order(root, result, dept);
            return result;
        }

        void order(TreeNode* cur, vector<vector<int>>& result, int dept) {
            if (!cur) return;
            if (result.size() == dept) result.push_back(vector<int> ());
            result[dept].push_back(cur->val);
            if (cur->left) order(cur->left, result, dept + 1);
            if (cur->right) order(cur->right, result, dept + 1);
        }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(4);
    Solution sol;
    printVec(sol.levelOrder(root));
    printVec(sol.levelOrder2(root));
    return 0;
}


