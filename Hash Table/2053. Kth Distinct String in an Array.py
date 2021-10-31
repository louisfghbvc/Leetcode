# O(N), two pass

class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        mp = Counter(arr)
        for s in arr:
            if mp[s] == 1:
                k -= 1
                if k == 0: return s
        return ''
        
