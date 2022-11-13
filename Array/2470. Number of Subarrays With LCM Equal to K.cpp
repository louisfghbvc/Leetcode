class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        // goal: find the number of subarray such that the lcm is k
        // idea: brute force?
        // 
        
        // lcm = a * b / gcd(a,b)
        // [3,6,2,7,1]
        //      ^
        // p=3
        // p=6
        // p=6
        // lcm(p, arr[j]) = lcm (arr[i], arr[i+1],... arr[j])
        
        // val1 = 2^x1 * 3^y1, val2 = 2^x2 * 3^y2
        // gcd = 2^min(x1,x2) * 3^min(y1,y2)
        // lcm = 2^max(x1,x2) * 3^max(y1,y2)
        
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int p = 1; // prefix lcm so far
            for (int j = i; j < n; ++j) {
                int g = __gcd(p, nums[j]);
                long lcm = p / g * nums[j];
                if (lcm == k) ans++;
                else if (lcm > k) break;
                p = lcm;
            }
        }
        
        return ans;
    }
};
