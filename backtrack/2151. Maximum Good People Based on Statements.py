# backtracking
# enumerate all bitmask
# and just check is valid or not

class Solution:
    def maximumGood(self, statements: List[List[int]]) -> int:
        n = len(statements)
        
        # enumerate all bitmask
        # check that if satisfied the statements
        good = 0
        for mask in range(1<<n):
            
            def check():
                for i in range(n):
                    if mask >> i & 1:
                        for j in range(n):
                            if mask >> j & 1:
                                if statements[i][j] == 0:
                                     return False
                            else:
                                if statements[i][j] == 1:
                                    return False
                return True
            
            if check():
                good = max(bin(mask).count('1'), good)
        
        return good
