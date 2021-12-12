# Simulate O(N)

class Solution:
    def minimumRefill(self, plants: List[int], capacityA: int, capacityB: int) -> int:
        # two pointers, simulate the process
        # when not enough, refill the water
        
        n = len(plants)
        l, r = 0, n-1
        
        refill = 0
        curA, curB = capacityA, capacityB
        while l <= r:
            if l == r:
                if max(curA, curB) < plants[l]:
                    refill += 1
                l += 1
                r -= 1
            else:
                curA -= plants[l]
                if curA < 0:
                    curA = capacityA - plants[l]
                    refill += 1
                curB -= plants[r]
                if curB < 0:
                    curB = capacityB - plants[r]
                    refill += 1
                l += 1
                r -= 1
    
        return refill
