# LIS O(N^2).
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        # sort by end point
        pairs.sort(key = lambda x: x[1])
        
        n = len(pairs)
        # dp[i]: 0~i, ending position i, longest length
        dp = [0] * n
        
        mx = 0
        for i in range(n):
            dp[i] = 1
            for j in range(i):
                if pairs[j][1] < pairs[i][0]:
                    dp[i] = max(dp[i], dp[j] + 1)
            mx = max(dp[i], mx)
            
        return mx

# Sort and Just care end point O(NlogN)
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        # sort by end point, ans is any order
        pairs.sort(key = lambda x: x[1])
        
        deck = []
        
        # only care end point, end point increasing
        for i in range(len(pairs)):
            # can append
            if not deck or deck[-1] < pairs[i][0]:
                deck.append(pairs[i][1])
        
        return len(deck)

# T:O(NlogN) S:O(1)
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        # sort by end point, ans is any order
        pairs.sort(key = lambda x: x[1])
        
        ans, endP = 0, pairs[0][0]-1 
        # only care end point, end point increasing
        for i in range(len(pairs)):
            # can append
            if endP < pairs[i][0]:
                endP = pairs[i][1]
                ans += 1
        
        return ans
