# BF. O(N^2)

class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        
        def vowel_substring(s):
            vowel = ['a', 'e', 'i', 'o', 'u']
            return len(set(s)) == 5 and all(c in s for c in vowel)
        
        res = 0
        for i in range(len(word)):
            j = 5
            while i+j <= len(word):
                res += vowel_substring(word[i:i+j])
                j += 1
        return res
        
# do like Prefix.


# Sliding window O(N)
