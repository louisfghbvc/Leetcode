# O(N)

class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
    
        # use hashtable to record the numbers    
        fre = Counter(nums)
        
        # just check the adjcacent values
        res = []
        for x in nums:
            if fre[x] > 1: continue
            if fre[x-1] == 0 and fre[x+1] == 0:
                res += x,
        
        return res
