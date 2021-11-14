# use counter, and just compare the frequency is is at most 3
# O(S + T)

class Solution:
    def checkAlmostEquivalent(self, word1: str, word2: str) -> bool:
        a, b = Counter(word1), Counter(word2)
        for i in range(26):
            af, bf = a[chr(i+97)], b[chr(i+97)]
            if abs(af - bf) > 3: return False
        return True
