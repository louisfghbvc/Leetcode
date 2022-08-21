class Solution {
public:
    
    vector<int> p;
    long mx = 0;
    vector<long> sum; // each segment sum
    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    
    void uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        sum[x] += sum[y];
        p[y] = x;
        mx = max(mx, sum[x]);
    }
    
    void add(int val) {
        mx = max<long>(mx, val);
    }
    
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        // goal: find the maximum segment sum for each query
        // idea: do it reverse, and use union find to merge the sum
        // maintain a maximum set when we union two index
        
        // [1, 2, 5, 6, 1]
        // (...),    i, (...)
        
        int n = nums.size();
        p = vector<int>(n, -1);
        sum = vector<long>(n);
        
        vector<long long> ans(n);
        unordered_set<int> ind;
        
        for (int i = n-1; i >= 0; --i) {
            ans[i] = mx;
            int idx = removeQueries[i];
            ind.insert(idx);
            
            sum[idx] += nums[idx]; // unique, sum == 0
            // add 
            add(nums[idx]);
            // union
            if (ind.count(idx-1)) // adjacent, merge the interval
                uni(idx, idx-1);
            if (ind.count(idx+1))
                uni(idx, idx+1);
        }
        
        return ans;
    }
};
