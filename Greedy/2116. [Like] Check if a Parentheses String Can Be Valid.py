# greedy appoarch
# just compute the maximum so far, and minimum so far
# O(N), O(1)

class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        # maintain maximum and minimum balance value

        maxC, minC = 0, 0
        for i, c in enumerate(s):
            if locked[i] == '0':
                maxC += 1
                minC -= 1
            else:
                if s[i] == '(':
                    maxC += 1
                    minC += 1
                else:
                    maxC -= 1
                    if maxC < 0: return False
                    minC -= 1
            minC = max(0, minC)
    
        return len(s) % 2 == 0 and minC == 0

    
# two pass, left to right, right to left
# just try to balance
