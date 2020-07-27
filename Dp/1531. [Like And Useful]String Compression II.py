// Very Smart solution...
// so just need to check last char.
// each have delete or not delete... some edge case check
// O(26*N^3)

class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        @lru_cache(None)
        def helper(ind, last, last_cnt, left):
            if left < 0:
                return float('inf')
            if ind >= len(s):
                return 0
            if s[ind] == last:
                inc = 1 if last_cnt == 1 or last_cnt == 9 or last_cnt == 99 else 0
                return inc + helper(ind + 1, last, last_cnt+1, left)
            else:
                keep_char = 1 + helper(ind + 1, s[ind], 1, left) 
                del_char = helper(ind + 1, last, last_cnt, left - 1) 
                return min(keep_char, del_char)
        return helper(0, "", 0, k)
