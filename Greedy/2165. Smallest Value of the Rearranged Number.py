class Solution:
    def smallestNumber(self, num: int) -> int:
        if num == 0: return num
        
        sign = num > 0
        
        digit = [0] * 10
        s = str(num)
        for c in s:
            if c.isdigit():
                digit[ord(c) - 48] += 1
        
        res = []
        # positive
        if sign:
            # first bit
            for i in range(1, 10):
                if digit[i]:
                    digit[i] -= 1
                    res += str(i),
                    break
            for i in range(10):
                for d in range(digit[i]):
                    res += str(i),
        
        # negative
        else:
            for i in range(9, -1, -1):
                for d in range(digit[i]):
                    res += str(i),
                    
        return int(''.join(res)) if sign else -int(''.join(res))
        
