#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
}

class Solution {
private:
    int getNodeNum(TreeNode* root) {
        if (cur == NULL) return 0;
        int leftnum = getNodeNum(root->left);
        int rightnum = getNodeNum(root->right);
        return leftnum + rightnum + 1;
    }
};

int main() {

}
