// 5 case. say a = nums[i], b = nums[n-1-i]. say T is what we want a+b. T in range(2, limit*2)
// so if T too small, need 2 operations. 
// min(a, b)+1 need 1 operation.
// a+b need 0.
// a+b+1 need 1.
// max(a+b) + limit + 1 need 2 operations
// so five segment.
// Use array tour so that what are min operations and T ? easy to observe. 

// use array tour to solve segment tree.

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int res = 1e9;
        int n = nums.size();
        vector<int> arr(limit*2+2);
        for(int i = 0; i < n/2; ++i){
            int a = nums[i], b = nums[n-1-i];
            arr[2] += 2;
            arr[min(a, b) + 1]--;
            arr[a + b]--;
            arr[a + b + 1]++;
            arr[max(a, b) + limit + 1]++;
        }
        
        int cur = 0;
        for(int x = 2; x <= limit * 2; ++x){
            cur += arr[x];
            res = min(cur, res);
        }
        
        return res;
    }
};
