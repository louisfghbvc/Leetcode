class Solution {
public:
    
    struct BIT{
        vector<int> bit;
        int N;
        
        BIT(int n) {
            N = n+1;
            bit.resize(N);
        }
        
        void add(int x, int v) {
            for (++x; x < N; x+=x&-x)
                bit[x] += v;
        }
        int sum(int x) {
            int res = 0;
            for (++x; x; x-=x&-x)
                res += bit[x];
            return res;
        }
    };
    
    long long countQuadruplets(vector<int>& nums) {
        // goal: given a permutation array
        // idea: find the number of increasing numbers
        // brute force: 4 for loops -> TLE
        
        // i < j < k < l
        //.1.  2.  3   4
        //     x. 
        // fix j
        // nums[k] < nums[j], 
        
        // (nums[i] < nums[k] < nums[j]) <  nums[l]
        //     1       3          2 
        // for j, 
        //.  for k in (j+1,n)
        //          find [k+1, n], nums[l] > nums[j]

        int n = nums.size();
        BIT bit1(n);
        
        long ans = 0;
        for (int j = 0; j < n; ++j) {
            int big = 0;
            for (int k = n-1; k >= j+1; --k) {
                if (nums[k] > nums[j]) big++;
                if (nums[k] < nums[j]) {
                    long val = bit1.sum(nums[k]);
                    ans += big*val;
                }
            }
            bit1.add(nums[j], 1);
        }
        
        return ans;
    }
};
