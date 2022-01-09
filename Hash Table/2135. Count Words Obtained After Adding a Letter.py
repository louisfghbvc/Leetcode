class Solution:
    def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
        # only can do append, rearrange exactly once

        # first convert to startWords into a dict
        # hasht has two types: int or str
        def conv_hash(str):
            res = 0
            for c in str:
                res |= 1<<(ord(c)-ord('a'))
            return res
        
        dc = set()
        for word in startWords:
            dc.add(conv_hash(word))
        
        # try to erase each letter in word, check if in dict or not
        
        ans = 0
        for word in targetWords:
            tmp = conv_hash(word)
            for i in range(25):
                if (tmp & (1<<i)) and (tmp ^ (1<<i)) in dc:
                    ans += 1
                    break
            
        return ans
