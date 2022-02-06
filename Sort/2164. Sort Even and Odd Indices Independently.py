class Solution:
    def sortEvenOdd(self, nums: List[int]) -> List[int]:
        # convert to two
        # odd array
        odd = []
        for i in range(1, len(nums), 2):
            odd += nums[i],
        # even array
        even = []
        for i in range(0, len(nums), 2):
            even += nums[i],
            
        odd.sort(key = lambda x: -x)
        even.sort()
        
        res = []
        idx0, idx1 = 0, 0
        # alternate put the array
        for i in range(len(nums)):
            if i % 2 == 0:
                res += even[idx0],
                idx0 += 1
            else:
                res += odd[idx1],
                idx1 += 1
        
        return res
