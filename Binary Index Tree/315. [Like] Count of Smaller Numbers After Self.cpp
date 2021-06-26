// just BIT, count numbers. O(NlogN).

class Solution {
public:
    
    vector<int> bit;
    
    void add(int x, int v){
        for(++x; x < bit.size(); x += x&-x)
            bit[x] += v;
    }
    
    int sum(int x){
        int res = 0;
        for(++x; x; x -= x&-x)
            res += bit[x];
        return res;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        
        for(auto &x: nums)
            x = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
        
        bit.resize(tmp.size()+1);
        
        int n = nums.size();
        vector<int> res(n);
        
        // from right.
        for(int i = n-1; i >= 0; --i){
            if(nums[i] == 0)
                res[i] = 0;
            else res[i] = sum(nums[i]-1);
            add(nums[i], 1);
        }
        
        return res;
    }
};
