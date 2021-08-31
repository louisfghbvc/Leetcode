"""
# Definition for an Interval.
class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end
"""

# just like line sweep, divide segment to 2 points. calculate frequencies
# sort by time, and traverse the time, when flow is 0.
# means the segment(prev time, cur time) is free time

class Solution:
    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        mp = defaultdict(int)
        for person in schedule:
            for it in person:
                mp[it.start] += 1
                mp[it.end] -= 1
        mp = sorted(mp.items(), key = lambda x: x[0])
        
        res = []
        prev_time, flow = -1, 0
        for t, cur in mp:
            if flow == 0:
                if prev_time >= 0:
                    res.append(Interval(prev_time, t))
            flow += cur
            prev_time = t
        return res
      
# use sorting, like LC merge intervals. O(NlogN).

class Solution:
    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        
        # flatten to '[Interval]', sort by start
        schedule = sorted([it for person in schedule for it in person], key=lambda x: x.start)
        
        res, prev = [], schedule[0]
        for it in schedule[1:]:
            # if covered, updated end
            if it.start <= prev.end and it.end > prev.end:
                prev.end = it.end
            # not covered, have new free time
            elif it.start > prev.end:
                res.append(Interval(prev.end, it.start))
                prev = it
                
        return res
      
# Use heap
