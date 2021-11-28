# enumerate 4 case.
# O(N), O(1) space
class Solution:
    def minimumBuckets(self, street: str) -> int:
        house_cnt = street.count('H')
        
        # all house
        if house_cnt == len(street): return -1
        
        # .H next: H or . 
        # ..
        
        # H. next: H or .
        # HH 
        
        cnt, i = 0, 0
        while i+1 < len(street):
            if street[i] == '.' and street[i+1] == '.': 
                pass
            elif street[i] == '.' and street[i+1] == 'H':
                if i+2 == len(street) or street[i+2] == 'H': 
                    cnt += 1
                    i += 1
            elif street[i] == 'H' and street[i+1] == '.':
                if i+2 == len(street) or street[i+2] == 'H': 
                    cnt += 1
                    i += 2
                else:
                    cnt += 1
                    i += 1
            else: # HH
                return -1
            i += 1        
        if i < len(street) and street[i] == 'H': return -1
        return cnt
      
# replace
# 3 pass
# count '!'
# O(N), space O(N)
class Solution:
    def minimumBuckets(self, street: str) -> int:
        street = street.replace('H.H', '!')
        street = street.replace('.H', '!')
        street = street.replace('H.', '!')
        return street.count('!') if 'H' not in street else -1

# O(N), O(1) space
# just see the house next is '.', ignore 3
class Solution:
    def minimumBuckets(self, street: str) -> int:
        
        res, i = 0, 0
        while i < len(street):
            if street[i] == 'H':
                if i+1 < len(street) and street[i+1] == '.':
                    res += 1
                    i += 3
                    continue
                if i and street[i-1] == '.':
                    i += 1
                    res += 1
                    continue
                return -1
            else: i += 1
        return res
