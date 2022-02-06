# backtracking. level is 4 

class Solution:
    def minCostSetTime(self, startAt: int, moveCost: int, pushCost: int, targetSeconds: int) -> int:
        # enumerate all possible digit from 00:01 to ~ 99:99
        
        # minimum cost to get target seconds
        self.mn = float('inf')
        
        def dfs(digit, prev=startAt, level=0, cost=0, leading_zero=True):
            if level == 4:
                # calculate the cost
                m = digit[0] * 10 + digit[1]
                sec = digit[2] * 10 + digit[3]
                if m * 60 + sec == targetSeconds:
                    self.mn = min(self.mn, cost)
                return
            
            if leading_zero:
                dfs(digit+[0], prev, level+1, cost, leading_zero)
            
            for i in range(10):
                digit += i,
                move = moveCost if i != prev else 0
                dfs(digit, i, level+1, cost + move + pushCost, False) 
                digit.pop()
            
        dfs([])
        
        return self.mn
