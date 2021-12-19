# O(Nlog(N/K))
# think reverse,
# convert each subgroup
# each just calculate the lis, since lis is the best

class Solution:
    def kIncreasing(self, arr: List[int], k: int) -> int:
        # compare the k pairs
        # calculate the lis in each subgroup
        
        def cal_lis(lt):
            lis = []
            for x in lt:
                if not lis or lis[-1] <= x:
                    lis.append(x)
                else:
                    lis[bisect_right(lis, x)] = x
            return len(lis)
        
        res = 0
        for i in range(k):
            tmp = []
            for j in range(i, len(arr), k):
                tmp.append(arr[j])
            res += len(tmp) - cal_lis(tmp)
        
        return res
