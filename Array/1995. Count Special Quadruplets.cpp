// Simliar to 4 sum, can use hashtable to speed up.
// O(N^4)
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int a = 0; a < n; ++a)
            for(int b = a+1; b < n; ++b)
                for(int c = b+1; c < n; ++c)
                    for(int d = c+1; d < n; ++d)
                        cnt += nums[a]+nums[b]+nums[c] == nums[d];
        return cnt;
    }
};

// Use 3 Hashtable. O(N * X)
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> _single, _double, _triple;
        for(int x: nums){
            cnt += _triple[x];
            for(auto &[d, v]: _double) if(d + x <= 100)
                _triple[d + x] += v;
            for(auto &[s, v]: _single) if(s + x <= 100)
                _double[s + x] += v;
            _single[x]++; 
        }
        return cnt;
    }
};
