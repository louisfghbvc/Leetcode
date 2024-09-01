class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        // goal: find the maximum subarray XOR value
        // idea:
        // given a query -> we need to find out all possible subarray maximum XOR!

        // what is the constraint?
        // n = 2000
        // we can brute force to pre compute the XOR values!
        // for each query just check out that
        // TC: O(n^2)
        // think dp
        // dp[l][r]: in nums[l:r], what is maximum XOR values
        // dp[i][i] = nums[i]
        // dfs(l, r) => max(XOR[l:r], dfs(l-1, r), dfs(l, r-1))
        // XOR score is not XOR value!!!!!!!!!!!
        // ...
        // [0010,1000,0100] => nums[i] 
        //. 1010 1100
        //.  0110

        // n = 2
        // nums[i] = nums[i]^nums[i+1]
        // n = 3
        // nums[i] = nums[i]^nums[i+2]
        // n = 4, if n is even
        // [a,b,c,d] = all elements XOR
        //. a^b,b^c,c^d
        //. a^c,b^d
        //  a^b^c^d
        // n = 6
        // [a,b,c,d,e,f]
        // a^b,b^c,c^d,d^e,e^f
        // a^c,b^d,c^e,d^f
        // a^c^b^d,b^d^c^e,cdef
        // ae,bf
        // aebf

        // [a,b,c,d,e]
        // a^b,b^c,c^d,d^e
        // a^c,b^d,c^e
        // a^b^c^d,b^c^d^e
        // a^e

        // if n is odd => nums[l]^nums[r]
        // else all
        // the problem is how to compute the XOR score???
        // consider 
        // can general to
        // XOR[l][r] = XOR[l][r-1] ^ XOR[l+1][r]
        // n=3
        // a,b,c 
        // a^b, b^c
        // n=4
        // a,b,c,d
        // ab,bc,cd
        // n=5
        // a,b,c,d,e
        // ab,bc,cd,de
        
        int n = nums.size();

        // tricky! we need to build dp first
        // then compute prefix suffix maximum!
        vector dp(n, vector(n, 0));
        for (int i = 0; i < n; ++i)
            dp[i][i] = nums[i];
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i+len-1;
                dp[i][j] = dp[i+1][j] ^ dp[i][j-1]; 
            }
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i+len-1;
                dp[i][j] = max({dp[i][j], dp[i+1][j], dp[i][j-1]});
            }
        }

        vector<int> res;
        for (auto &q: queries) {
            res.push_back(dp[q[0]][q[1]]);
        }
        return res;
    }
};
