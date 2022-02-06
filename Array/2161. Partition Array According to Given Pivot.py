class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        
        # partition to 3 array
        
        small, equal, bigger = [], [], []
        for x in nums:
            if x < pivot:
                small += x,
            elif x == pivot:
                equal += x,
            else:
                bigger += x,
        
        
        return small + equal + bigger
            
