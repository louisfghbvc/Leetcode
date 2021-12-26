# BF, just simulate

class Solution:
    def executeInstructions(self, m: int, startPos: List[int], s: str) -> List[int]:
        s = list(s)
        
        # execute the instructions from i
        def execute(i):
            x, y = startPos[0], startPos[1]
            j = i
            while j < len(s):
                if s[j] == 'R':
                    y += 1
                if s[j] == 'L':
                    y -= 1
                if s[j] == 'U':
                    x -= 1
                if s[j] == 'D':
                    x += 1
                if not(0 <= x < m and 0 <= y < m): break
                j += 1
            return j-i
        
        return [execute(i) for i in range(len(s))]
