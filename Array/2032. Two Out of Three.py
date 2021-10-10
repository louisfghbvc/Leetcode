# simple, and O(N^2)
# can use hashtable to speed up

class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        res = set()
        for x in nums1:
            if x in nums2 or x in nums3:
                res.add(x)
        for x in nums2:
            if x in nums1 or x in nums3:
                res.add(x)
        for x in nums3:
            if x in nums1 or x in nums2:
                res.add(x)
        
        return list(res)
        
