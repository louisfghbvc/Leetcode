# try all k, and try to pair them, constructive algorithm
# O(N^2)

class Solution:
    def recoverArray(self, nums: List[int]) -> List[int]:
        # higher[i] - lower[i] = 2*k
        # higher[i] + lower[i] = 2*arr[i]
        
        # do it from small
        nums.sort()
        n = len(nums)//2
        
        # find k which is even and smallest
        all_k = []
        for i in range(1, n*2):
            dif = nums[i] - nums[0]
            if dif and dif % 2 == 0:
                all_k += dif,
        
        # try all k, and try to pair
        for k in all_k:
            mp = Counter(nums)
            res = []
            for i in range(n*2):
                lower = nums[i]
                higher = lower + k
                if not mp[lower]: continue
                res += (higher + lower)//2,
                if mp[higher]:
                    mp[lower] -= 1
                    mp[higher] -= 1
                else:
                    break
            if len(res) == n:
                return res
        
        return res
