# find first b, then find a

class Solution:
    def checkString(self, s: str) -> bool:
        if 'b' not in s: return True
        # find first b
        # after first b
        # find a
        firstb = s.index('b')
        while firstb < len(s):
            if s[firstb] == 'a': return False
            firstb += 1
        return True
