# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# post order, just try to enumerate each node. and calculate value, and node numbers.
# O(N)
class Solution:
    def maximumAverageSubtree(self, root: Optional[TreeNode]) -> float:
        self.ans = 0.0
        
        # node val, numbers of node
        def dfs(root):
            if not root: return (0, 0)
            left = dfs(root.left)
            right = dfs(root.right)
            self.ans = max(self.ans, (root.val + left[0] + right[0]) / (right[1] + left[1] + 1))
            return (left[0] + right[0] + root.val, left[1] + right[1] + 1) 
        dfs(root)
        return self.ans
            
        
