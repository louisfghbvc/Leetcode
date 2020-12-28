// O(N).
// So record index. make it continuous.
// e.g ind = [0, 2, 3, 5, 7]. k = 3. we want to smallest move. so move to medium. cost smallest
// and sliding window.
// [0, 2, 3]. => 2-0 + 2-2 + 3-2. => 3 - 0. so maintain prefix sum.
// after that we need to flatten. 3
//                                3 => 3 3 3
//                                3
// what about k is even ? [0, 2, 3, 5] => 2-0 + 2-2 + 3-2 + 5-2 => 3+5 - 0 - 2
// flatten and calculate radius. [3 3 3] -> [1, 0, 1].
// watch out overflow.

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        long res = LLONG_MAX, n = nums.size();
        vector<int> arr;
        for(int i = 0; i < n; ++i) if(nums[i]) arr.push_back(i);
        
        n = arr.size();
        vector<long> pre(n+1);
        for(int i = 1; i <= n; ++i) pre[i] = pre[i-1] + arr[i-1];
        
        int rad = (k-1) / 2;
        for(int l = 1, r = k; r <= n; ++l, ++r){
            int mid = (l + r) / 2;
            long left = pre[mid-1] - pre[l-1];
            long right = pre[r] - pre[mid];
            long sub = (rad+1)*rad;
            if(k % 2 == 0) sub += arr[mid-1] + rad+1;
            res = min(res, right - left - sub);
        }
        
        return res;
    }
};
