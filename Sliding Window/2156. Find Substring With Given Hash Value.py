# simple rolling hash, sliding window

class Solution:
    def subStrHash(self, s: str, power: int, modulo: int, k: int, hashValue: int) -> str:
        n = len(s)
        s = s[::-1]
        
        # sliding window with length about k
        
        value = 0
        for i in range(k):
            value = value * power + ord(s[i]) - 96
            value %= modulo
        
        highest_power = pow(power, k-1, modulo) 
        
        # do it from reverse
        ans = ''
        if value == hashValue:
            ans = s[:k][::-1]
        
        l = 0
        for r in range(k, n, 1):
            value -= (ord(s[l]) - 96) * highest_power % modulo
            if value < modulo:
                value += modulo
            value = value * power + ord(s[r]) - 96
            value %= modulo
            
            l += 1
            # find the value
            if value == hashValue:
                ans = s[l:r+1][::-1]
    
        return ans
