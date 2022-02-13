# just two case 
# O(N)

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        
        # [3,1,3,2,4,3], ans = 3
        #  x y x y x y
        # [1,2,2,2,2], ans != 1, ans = 2
        #  x y x y x
        
        # 1. even index and odd index all the number should be same
        # 2. odd != even
        
        odd, even = Counter(), Counter()
        oc, ec = 0, 0
        for i, x in enumerate(nums):
            if i & 1:
                odd[x] += 1
                oc += 1
            else:
                even[x] += 1
                ec += 1
        
        def find2Max(dic):
            mx1, mx2 = -1, -1
            for k, v in dic.items():
                if mx1 < 0 or v > dic[mx1]:
                    mx2 = mx1
                    mx1 = k
                elif mx2 < 0 or v > dic[mx2]:
                    mx2 = k
            return (mx1, mx2)
        
        ans1, ans2 = find2Max(odd), find2Max(even)
        
        if ans1[0] == ans2[0]:
            return min((oc - odd[ans1[0]]) + (ec - even[ans2[1]]), (oc - odd[ans1[1]]) + (ec - even[ans2[0]]))
        else:
            return (oc - odd[ans1[0]]) + (ec - even[ans2[0]])
