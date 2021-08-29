# main idea is sum1[i:j] - sum2[i:j] is 0
# and use a prefix map to do that. remember default mp[0] = -1
class Solution:
    def widestPairOfIndices(self, nums1: List[int], nums2: List[int]) -> int:
        res, prev = 0, 0
        mp = {0: -1}
        # use a mp to record index of same diff
        for i in range(len(nums1)):
            prev += nums1[i] - nums2[i]
            if prev in mp:
                res = max(res, i - mp[prev])
            else:
                mp[prev] = i
        return res
