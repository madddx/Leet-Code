# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
	
        def inorder_t(root):
            
            if not root: return []
            
            return inorder_t(root.left)+[root.val]+inorder_t(root.right)
                
        inorder=inorder_t(root)
        
        def balance_tree(s,e):
            
            if s>e:
                return None
            
            mid=(s+e)//2
            root=TreeNode(inorder[mid])
            root.left=balance_tree(s,mid-1)
            root.right=balance_tree(mid+1,e)
                
            return root
            
        return balance_tree(0,len(inorder)-1)
