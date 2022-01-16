class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        res = []
        
        i = 0
        cur = []
        while i < len(s):
            cur += s[i],
            i += 1
            if len(cur) == k:
                res += ''.join(cur),
                cur = []
        
        if len(cur):
            while len(cur) < k:
                cur += fill,
            res += ''.join(cur),
        
        return res
