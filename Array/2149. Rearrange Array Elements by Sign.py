class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        
        # divide to positive and negative numbers
        
        pos, neg = [], []
        
        for x in nums:
            if x > 0:
                pos += x,
            else:
                neg += x,
        
        
        res = []
        for i in range(len(pos)):
            res += pos[i],
            res += neg[i],
        
        return res
