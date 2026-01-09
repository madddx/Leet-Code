# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def subtreeWithAllDeepest(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        
        def dfs(root):
            if not root:
                return 0, None
            dl, l = dfs(root.left)
            dr, r = dfs(root.right)
            if dl == dr:
                return dl+1, root
            if dl > dr:
                return dl+1, l
            return dr+1, r


        _, ans = dfs(root)
        return ans
