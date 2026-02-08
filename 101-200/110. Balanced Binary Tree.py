# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def height(self, root, ans):
        if root is None:
            return 0

        leftHeight = 1 + self.height(root.left, ans)
        rightHeight = 1 + self.height(root.right, ans)

        if abs(leftHeight - rightHeight) > 1:
            ans[0] = False
            return 0

        return max(leftHeight, rightHeight)

    def isBalanced(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        ans = [True]
        self.height(root, ans)
        return ans[0]
