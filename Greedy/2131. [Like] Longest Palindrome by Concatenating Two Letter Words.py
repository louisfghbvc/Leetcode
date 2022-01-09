# first pass, use counter, record the string
# and when reverse part exist
# add 4
# second pass, is that if have self_palindrome, add to ans

class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        # use a set to record palindrome
        
        palindrome = 0
        prev_words = Counter()
        for word in words:
            if prev_words[word[::-1]] > 0:
                palindrome += 4
                prev_words[word[::-1]] -= 1
            else:
                prev_words[word] += 1

        self_palindrome = 0
        for word in prev_words:
            if prev_words[word] and word == word[::-1]:
                self_palindrome = 2
    
        return palindrome + self_palindrome
                
        
