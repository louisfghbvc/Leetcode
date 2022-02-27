# O(NlogX)

class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        
        # give u a time, can easily calculate the number of trip per bus can travel
        # sum it up, and check if greater than totalTrips
        # binary search the time
        
        
        l, r = 0, min(time) * totalTrips
        ans = 0
        
        while l <= r:
            mid = (l + r) // 2
            
            tmpTrips = 0
            for bus in time:
                tmpTrips += mid // bus
                        
            if tmpTrips >= totalTrips:
                ans = mid
                r = mid-1
            else:
                l = mid+1
        
        return ans
        
        
        
