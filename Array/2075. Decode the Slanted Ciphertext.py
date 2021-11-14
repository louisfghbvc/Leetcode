# O(N*M), just array to 1D pointers.

class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        n = len(encodedText)
        cols = n // rows
        
        res = []
        
        # try to traverse each col, go right down
        for j in range(cols-1):
            x, y = 0, j
            while x < rows and y < cols:
                res += encodedText[x * cols + y]
                x += 1
                y += 1
        
        # del trailing zero
        while res and res[-1] == ' ': res.pop()
        
        return ''.join(res)
