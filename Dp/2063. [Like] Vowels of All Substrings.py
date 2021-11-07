# prefix dp O(N)
# two case, vowel or non-vowel
class Solution:
    def countVowels(self, word: str) -> int:
        n = len(word)

        vowel = {'a', 'e', 'i', 'o', 'u'}
        
        # not vowel: copy from previous sum
        # 0 0 0
        # 1 0 
        
        # vowel: copy from previous sum + i + 1
        # 1 0 4
        
        res = 0
        pre = 0
        for i in range(n):
            if word[i] in vowel:
                pre = pre + i + 1
            res += pre
        return res
      
# calculate the left, right possible (i+1) * (N-i)
class Solution:
    def countVowels(self, word: str) -> int:
        n = len(word)        
        vowel = {'a', 'e', 'i', 'o', 'u'}
        
        res = 0
        for i in range(n):
            if word[i] in vowel:
                res += (i+1) * (n-i)
        return res
