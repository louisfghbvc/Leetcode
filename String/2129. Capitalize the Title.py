# string process
# simulate
# O(N)

class Solution:
    def capitalizeTitle(self, title: str) -> str:
        
        # split the word
        # then check size is 1 or 2
        words = title.split()
        
        res = []
        for word in words:
            if len(word) == 1 or len(word) == 2:
                res += word.lower(),
            else:
                res += word[0].upper(), 
                res += word[1:].lower(),
            res += ' ',
        
        res.pop()
        return ''.join(res)
