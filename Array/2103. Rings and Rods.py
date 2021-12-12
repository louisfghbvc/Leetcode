# record each position if have RGB, add ans
# O(S)

class Solution:
    def countPoints(self, rings: str) -> int:
        
        # record each position RGB
        mp = defaultdict(set)
        
        for i in range(0, len(rings), 2):
            mp[ord(rings[i+1])-48].add(rings[i])
        
        return sum(1 for val in mp.values() if len(val) >= 3)
                
