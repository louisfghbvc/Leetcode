# worst O(30*2^10). convert prime to bitmask
# Comb dp.
# Duplicate just use Counter to do that. and multiply.

class Solution:
    def numberOfGoodSubsets(self, nums: List[int]) -> int:
        # compress prime to int
        primes = [2,3,5,7,11,13,17,19,23,29] 
        fre = Counter(nums)
        
        conv_num = dict()
        for key in fre.keys():
            if key == 1: continue
            cur = 0
            for i, p in enumerate(primes):
                if key % p == 0:
                    if key % (p*p) == 0: break
                    cur |= 1<<i
            else:
                conv_num[key] = cur
        
        mod = 10**9 + 7
        nums = list(conv_num.keys())
        
        @lru_cache(None)
        def dfs(i, dc):
            if i >= len(nums): return dc > 0 
            res = 0
            if dc & conv_num[nums[i]] == 0:
                res += dfs(i+1, dc | conv_num[nums[i]]) * fre[nums[i]]
            res += dfs(i+1, dc)
            return res % mod
        
        res = dfs(0, 0)
        return res * pow(2, fre[1], mod) % mod
