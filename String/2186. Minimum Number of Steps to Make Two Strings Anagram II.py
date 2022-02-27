# record frequency
# compute the abs.

class Solution:
    def minSteps(self, s: str, t: str) -> int:
        
        # record the frequencies of two string
        # calculate the abs difference
        
        sc, tc = Counter(), Counter()
        for c in s:
            sc[ord(c) - ord('a')] += 1
        for c in t:
            tc[ord(c) - ord('a')] += 1
        
        dif = 0
        for i in range(26):
            dif += abs(sc[i] - tc[i])
        
        return dif
