# two dfs. check root O(N)
class Solution:
    def checkEqualTree(self, root: Optional[TreeNode]) -> bool:
        
        def dfs1(root): 
            return root.val + dfs1(root.left) + dfs1(root.right) if root else 0
        
        # total sum
        tot = dfs1(root)
        
        self.ans = False
        def dfs(root, par):
            if not root: return 0
            left = dfs(root.left, par)
            right = dfs(root.right, par)
            cur = left + right + root.val
            if root != par:
                self.ans = self.ans or (cur == tot - cur)
            return cur
        
        dfs(root, root)
        return self.ans

# O(N), use hashmap  
