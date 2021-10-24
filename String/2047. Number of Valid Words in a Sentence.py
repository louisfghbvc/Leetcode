class Solution:
    def countValidWords(self, sentence: str) -> int:
        s = sentence.split()
        
        cnt = 0
        for word in s:
            hy = word.count('-')
            pun = word.count('!')+word.count('.')+word.count(',')
            if pun > 1 or hy > 1 or word[0] == '-' or word[-1] == '-': continue
            if pun == 1 and word[-1] not in {'!', '.', ','}: continue
            
            # one '-'
            if hy == 1:
                i = 0
                while i < len(word):
                    if word[i] == '-': break
                    i += 1
                if i == 0 or i == len(word)-1: continue
                if not word[i-1].isalpha() or not word[i+1].isalpha(): continue
            
            # has digit
            if any(c for c in word if c.isdigit()): continue
            cnt += 1
        
        return cnt
            
            
        
