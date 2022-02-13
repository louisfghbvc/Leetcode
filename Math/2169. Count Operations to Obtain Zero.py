# O(log(max(num1, num2)))

class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        # simulate the process
        # O(num)
        
        ops = 0
        while num1 and num2:
            if num1 >= num2:
                ops += num1 // num2
                num1 %= num2
            else:
                ops += num2 // num1
                num2 %= num1
            
        return ops
