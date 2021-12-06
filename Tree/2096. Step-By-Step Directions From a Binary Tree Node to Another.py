# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# two steps, construct, simulate
# first is find lca
# because lca is the shortest path
# second is find path

class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        self.first, self.second = [], []
        
        self.way = []
        def calPath(root):
            if not root: return
            if root.val == startValue: 
                self.first = ['U'] * len(self.way) 
            if root.val == destValue: 
                self.second = self.way.copy()
            self.way += 'L',
            calPath(root.left)
            self.way.pop()
            
            self.way += 'R',
            calPath(root.right)
            self.way.pop()
        
        # find lca
        def dfs(root):
            if not root: return None
            if root.val in [startValue, destValue]:
                return root
            left = dfs(root.left)
            right = dfs(root.right)
            if left and right: return root
            return right if right else left
        
        lca = dfs(root)
        calPath(lca)
        
        return ''.join(self.first+self.second)
      
# solution2 remove common prefix, awesome clean
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        def find(root, val, path) -> bool:
            if root.val == val:
                return True
            if root.left and find(root.left, val, path):
                path += 'L'
            elif root.right and find(root.right, val, path):
                path += 'R'
            return path
        
        start, dest = [], []
        # postorder
        find(root, startValue, start)
        find(root, destValue, dest)
        
        # remove common prefix
        while start and dest and start[-1] == dest[-1]:
            start.pop()
            dest.pop()
        
        return ''.join('U' * len(start)) + ''.join(dest[::-1])
