# sorting, greedy
# O(1)

class Solution:
    def minimumSum(self, num: int) -> int:
        # sort the number by incre
        st = list(str(num))
        st.sort()
        
        num1 = []
        num2 = []
        isnum1 = True
        for x in st:
            if isnum1:
                num1 += x,
            else:
                num2 += x,
            isnum1 ^= 1
        
        return int(''.join(num1)) + int(''.join(num2))
