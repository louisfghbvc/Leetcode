# Simple O(N). just use map to count the number of the window.
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        res = []
        mp = defaultdict(int)
        for i in range(len(s)-9):
            mp[s[i:i+10]] += 1
            if mp[s[i:i+10]] == 2:
                res.append(s[i:i+10])
        return res
        
