# [2333. Minimum Sum of Squared Difference](https://leetcode.com/problems/minimum-sum-of-squared-difference/)

###### tags: `leetcode` `medium` `greedy`

[TOC]

## Description
You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.

The sum of squared difference of arrays nums1 and nums2 is defined as the sum of (nums1[i] - nums2[i])2 for each 0 <= i < n.

You are also given two positive integers k1 and k2. You can modify any of the elements of nums1 by +1 or -1 at most k1 times. Similarly, you can modify any of the elements of nums2 by +1 or -1 at most k2 times.

Return the minimum sum of squared difference after modifying array nums1 at most k1 times and modifying array nums2 at most k2 times.

Note: You are allowed to modify the array elements to become negative integers.

## Way1 - Greedy + Sort

> Note: make sure the height is greater than zero
> should use remain to keep value correct

```c++
class Solution {
public:
    
    void fillK(vector<int> &arr, int k) {        
        long sum = 0;
        int i = 0, n = arr.size();
        while (i < n && sum - (long)arr[i]*i <= k) sum += arr[i++];
        int height = max(sum - k, 0L) / i, r = max(sum - k, 0L) % i;
        for (int j = 0; j < i; ++j) {
            arr[j] = height;
            if (j < r)
                arr[j]++;
        }
    }
    
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // goal: minimum the sum of square difference
        // idea: k1, k2 is the same
        // we calculate the absolute difference
        // choose the maximum difference to 
        
        int k = k1+k2;
        int n = nums1.size();
        vector<int> diff(n);
        
        for (int i = 0; i < n; ++i)
            diff[i] = abs(nums1[i] - nums2[i]);
        
        // desc
        sort(diff.rbegin(), diff.rend());
        
        fillK(diff, k);
        
        long res = 0;
        for (int x: diff)
            res += (long)x*x;
        return res;
    }
};
```

## Way2 - Binary Search

> Note: easy to think, bug free

```c++
class Solution {
public:
    
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // goal: minimum the sum of square difference
        // idea2: k1, k2 is the same
        // we calculate the absolute difference
        // binary search 
        
        int k = k1+k2;
        int n = nums1.size();
        vector<int> diff(n);
        
        for (int i = 0; i < n; ++i)
            diff[i] = abs(nums1[i] - nums2[i]);
        
        // make all the value at most x
        auto cal = [&](int x) {
            long ops = 0;
            for (int v: diff) {
                ops += max(0, v-x);
            }
            return ops;
        };
        
        int l = 0, r = 1e9;
        int ans = 1e9;
        while (l <= r) {
            int mid = (l+r)/2;
            if (cal(mid) <= k) r = mid-1, ans = mid;
            else l = mid+1;
        }
        
        long res = 0;
        k -= cal(ans);
        for (int x: diff) {
            if (x >= ans) {
                x = ans;
                if (k) {
                    k--;
                    x = max(0, x-1);
                }
            }
            res += (long)x*x;
        }
        
        return res;
    }
};
```

## Way3 - Bucket Sort

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(nlogn) | O(n) |
| Way2 | O(nlogv) | O(n) |
| Way3 | O(max(value, n)) | O(value) |

