# group value
# and for each value, compute the ans
# just use prefix and suffix to record the value so far
# and try to remove the abs| |
# O(N)

class Solution:
    def getDistances(self, arr: List[int]) -> List[int]:
        n = len(arr)
        
        # record the index
        mp = defaultdict(list)
        for i in range(n):
            mp[arr[i]].append(i) 
        
        res = [0] * n
        # for each list, we compute the prefix sum
        # divide to left sum, right sum, calculate the ans
        
        for val, lt in mp.items():
            m = len(lt)
            pre = [0]
            for i in range(m):
                pre += pre[-1] + lt[i],

            left_cnt, right_cnt = 0, m-1
            for i in range(m):
                left_ans = left_cnt * lt[i] - pre[i]
                right_ans = pre[-1] - pre[i+1] - right_cnt * lt[i]
                res[lt[i]] = left_ans + right_ans
                left_cnt += 1
                right_cnt -= 1
            
        return res
        
