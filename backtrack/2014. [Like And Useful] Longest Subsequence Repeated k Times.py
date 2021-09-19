# Backtracking. search bound is small. and pattern is small

class Solution:
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:

        n = len(s)
        mp = Counter(s)
        chars = [p for p in mp if mp[p] >= k]

        candidates = []
        tmp = []
        
        # gen all pattern is dep, up to O(26^8). but impossible
        def dfs(i, dep):
            if i == dep:
                candidates.append("".join(tmp))
                return
            for c in chars:
                if mp[c] < k: continue
                tmp.append(c)
                mp[c] -= k
                dfs(i + 1, dep)
                mp[c] += k
                tmp.pop()
        
        # O(S + t * k)
        def isSubseq(t):
            it = iter(s)
            t = t * k
            return all(c in it for c in t)
        
        def helper(length):
            dfs(0, length)
            candidates.sort()
            for t in candidates[::-1]:
                if not isSubseq(t): continue
                return (True, t)
            return (False, None)
        
        l, r = 1, n//k + 1
        ans = ''
        while l < r:
            length = (l + r)//2
            possible, cur = helper(length)
            candidates, tmp = [], []
            if possible:
                ans = cur
                l = length + 1
            else:
                r = length
        
        return ans
