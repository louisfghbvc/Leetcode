# just compare reverse string is equal to string
# O(N*Len)

class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for s in words:
            if s == s[::-1]:
                return s
        return ""
