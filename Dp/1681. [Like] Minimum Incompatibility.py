# O(?). Just bruteforce... python is really cool.
# Enum all subset size == d. remove it. and dfs it.

class Solution:
    def minimumIncompatibility(self, nums: List[int], k: int) -> int:
        d = len(nums) // k
        
        @lru_cache(None)
        def dfs(nums):
            if not nums: return 0
            res = 10**15
            for can in combinations(set(nums), d):
                left = list(nums)
                for c in can:
                    left.remove(c)
                res = min(res, max(can)-min(can) + dfs(tuple(left)))
            return res
        res = dfs(tuple(nums))
        
        return -1 if res == 10**15 else res
