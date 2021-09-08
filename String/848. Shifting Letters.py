# From backward, since each will shift [0:i+1] letter. O(N)
class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        
        # from backward
        shift = 0
        p = ''
        for i in range(len(s)-1, -1, -1):
            shift = (shift + shifts[i]) % 26
            p += chr(((ord(s[i]) - 97) + shift) % 26 + 97)
        
        return p[::-1]
