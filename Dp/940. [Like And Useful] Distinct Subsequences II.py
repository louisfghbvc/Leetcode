# endwith comb dp, each char can endwith all 26 chars
# O(26N)
class Solution:
    def distinctSubseqII(self, s: str) -> int:
        arr, mod = [0] * 26, 10**9 + 7
        for c in s:
            arr[ord(c)-97] = (sum(arr) + 1) % mod
        return sum(arr) % mod
