# math and greedy. hard to think.
# O(N).

class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        if len(stones) == 1: return False
        
        cnt = Counter([x % 3 for x in stones])
        
        # no choose
        if cnt[1] + cnt[2] == 0: return False
        
        # first go 0
        alice = cnt[0] % 2
        
        res = False
        # alice going to 1
        if cnt[1]: 
            # only 1 cnt > 2 cnt, can win
            if cnt[1] > cnt[2]:
                if alice: res |= cnt[1]-1 - cnt[2] >= 2
            else:
                res |= not alice
        
        if cnt[2]:
            # only 2 cnt > 1 cnt, can win
            if cnt[2] > cnt[1]:
                if alice: res |= cnt[2]-1 - cnt[1] >= 2
            else:
                res |= not alice
                
        return res
      
      
# lee 2 liner. cool
class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        cnt = Counter(x % 3 for x in stones)
        return cnt[1] > 0 and cnt[2] > 0 and (cnt[0] % 2 == 0 or abs(cnt[1]-cnt[2]) > 2)
