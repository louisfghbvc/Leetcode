# convert to dfs find the longest path.
# O(N)

class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        n = len(nums)
        vis = [0] * n
        
        def dfs(k):
            if vis[nums[k]]: return 0
            vis[nums[k]] = 1
            return 1 + dfs(nums[k])
        
        # convert the problem to dfs.
        # find the longest path
        res = 0
        for i in range(n):
            if not vis[i]:
                res = max(res, dfs(i))
        return res
