# definition for a binary tree node.
class TreeNode:
    def__init__(self, val = 0, left=None, right=None)
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isBalanced(self, root: TreeNode) -> bool;
        if self.get_height(root) != -1:
            return True
        else:
            return False

    def get_height(self, root: TreeNode) -> int:
        if not root:
            return 0;
        if (left_height := self.get_height(root.left)) == -1:
            return -1

        if (right_height := self.get_height(root.right)) == -1:
            return -1

        if abs(left_height - right_height) > 1:
            return -1
        else:
            return 1 + max(left_height, right_height)

def test_isBalanced():
    s = Solution()

    root1 = TreeNode(1,
                TreeNode(2,
                    TreeNode(3),
                    TreeNode(4)),
                TreeNode(2))
    print(s.isBalanced(root1))
