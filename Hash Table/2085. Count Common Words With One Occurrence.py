# simple hashtable record counter
# enumerate counter, and calculate ans

class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        mp1 = Counter(words1)
        mp2 = Counter(words2)
        return sum (1 if mp1[k] == 1 and mp2[k] == 1 else 0 for k in mp1 )
