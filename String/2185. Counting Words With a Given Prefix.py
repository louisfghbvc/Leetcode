# just use substr to check
# O(NP)
class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        return sum(1 for w in words if w[:len(pref)] == pref)
