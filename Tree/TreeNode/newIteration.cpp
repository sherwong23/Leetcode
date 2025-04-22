#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<pair<TreeNode*, bool>> st;
        if (root != nullptr) 
            st.push(make_pair(root, false));

        while (!st.empty()) {
            TreeNode* cur = st.top().first;
            bool visited = st.top().second;
            st.pop();

            if (visited) {
                result.push_back(cur->val);
                continue;
            }

            //存入右节点和cur进栈,未来使用
            if (cur->right) {
                st.push(make_pair(cur->right, false));
            }
            //再次遇到中间节点时,直接处理.
            st.push(make_pair(cur, true));
            //最后放的是左节点,下个循环处理栈尾的左节点,
            if (cur->left) {
                st.push(make_pair(cur->left, false));
            }
        }
        return result;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<pair<TreeNode*, bool>> st;
        if (root != nullptr) 
            st.push(make_pair(root, true));

        while (!st.empty()) {
            TreeNode* cur = st.top().first;
            bool visited = st.top().second;
            st.pop();
            result.push_back(cur->val);

            if (cur->right) {
                st.push(make_pair(cur->right, true));
            }
            if (cur->left) {
                st.push(make_pair(cur->left, true));
            }
        }
        return result;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<pair<TreeNode*, bool>> st;
        if (root != nullptr) 
            st.push(make_pair(root, false));

        while (!st.empty()) {
            TreeNode* cur = st.top().first;
            bool visited = st.top().second;
            st.pop();

            if (visited) {
                result.push_back(cur->val);
                continue;
            }

            st.push(make_pair(cur, true));
            if (cur->right) {
                st.push(make_pair(cur->right, false));
            }
            if (cur->left) {
                st.push(make_pair(cur->left, false));
            }
        }
        return result;
    }
};


void printVec(vector<int> nums) {
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    vector<int> result;
    Solution sol;
    printVec(sol.preorderTraversal(root));
    printVec(sol.inorderTraversal(root));
    printVec(sol.postorderTraversal(root));
    return 0;
}

