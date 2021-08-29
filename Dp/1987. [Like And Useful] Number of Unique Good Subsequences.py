# similiar with digit dp, only consider not leading zero
class Solution:
    def numberOfUniqueGoodSubsequences(self, binary: str) -> int:
        mod = 10**9 + 7
        end0, end1, has0 = 0, 0, 0
        for c in binary:
            if c == '1':
                end1 = (end1 + end0 + 1) % mod
            else:
                end0 = (end1 + end0) % mod
                has0 = 1
        return (end1 + end0 + has0) % mod
