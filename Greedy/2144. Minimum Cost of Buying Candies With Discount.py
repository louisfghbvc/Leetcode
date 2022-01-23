// sort from big to small.
// O(nlogn)

class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(key = lambda x: -x)
        
        res, i = 0, 0
        while i < len(cost):
            res += cost[i]
            if i+1 < len(cost):
                res += cost[i+1]
                i += 2
            i += 1
        return res
