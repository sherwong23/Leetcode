#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution {
    public:
    vector<int> recursion (TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            //取出当前节点,弹出,放入res,对应前序遍历
            TreeNode* cur = st.top();
            st.pop();
            result.push_back(cur->val);
            //放入两个子节点,后放left先弹left
            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);
        }
        return result;
    }

    vector<int> recursion2 (TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root == NULL) return result;
        TreeNode* cur = root;
        //一个条件用于遍历到最后一个左节点,一个用于退出,很特殊的写法
        while (cur != NULL || !st.empty()){
            //先遍历到最后一个左节点
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;
            }
            //找到最左的null,弹出栈尾端的上个母节点(可能跳很远),再去往母节点的右节点(继续找最左的null),对应中序遍历
            else {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }

    vector<int> recursion3(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            //弹出栈尾值
            TreeNode* cur;
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            //放入左右节点进栈
            if (cur->left) st.push(cur->left);
            if (cur->right) st.push(cur->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    void printVec(vector<int> result) {
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<int> result;
    Solution sol;
    sol.printVec(sol.recursion(root));
    sol.printVec(sol.recursion2(root));
    sol.printVec(sol.recursion3(root));
    return 0;
}



