class Solution {
public:
    
    vector<int> arr, isPeak;
    
    vector<int> tree; 
    void build(int id, int l, int r) {
        if (l == r) {
            tree[id] = isPeak[l];
            return;
        }
        int m = (l+r)/2;
        build(id*2+1, l, m);
        build(id*2+2, m+1, r);
        tree[id] = tree[id*2+1] + tree[id*2+2];
    }
    
    int query(int id, int l, int r, int ll, int rr) {
        if (r < ll || l > rr) return 0;
        if (ll <= l && r <= rr) return tree[id];
        int m = (l+r)/2;
        int left = query(id*2+1, l, m, ll, rr);
        int right = query(id*2+2, m+1, r, ll, rr);
        return left + right;
    }
    
    void update(int id, int l, int r, int x, int val) {
        if (r < x || l > x) return;
        if (l == r && l == x) {
            tree[id] = val;
            return;
        }
        int m = (l+r)/2;
        update(id*2+1, l, m, x, val);
        update(id*2+2, m+1, r, x, val);
        tree[id] = tree[id*2+1] + tree[id*2+2];
    }
    
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        // goal: 
        // op1: count the peaks in range[l,r]
        // op2: change index i, nums[i] to val
        // idea:
        // just do segment tree, when into leaf node, check that can be a peak
        
        // convert nums into boolean array, do prefix sum
        // nums = [3,1,4,2,5], queries = [[2,3,4],[1,0,4]]
        //         0 0 1 0 0
        //         [   ]
        
        // original array, index i isPeak
        // segment tree -> only record the isPeak
        
        // 1. build the tree
        // 2. query
        // 3. update
        
        this->arr = nums;
        int n = arr.size();
        this->isPeak.assign(n, false);
        for (int i = 1; i+1 < n; ++i)
            isPeak[i] = arr[i] > arr[i-1] && arr[i] > arr[i+1];
        tree.assign(4*n, 0);
        
        // build tree of isPeak
        build(0, 0, n-1);
        
        auto updatePeak = [&](int x) -> void {
            if (x != 0 && x != n-1) {
                isPeak[x] = arr[x] > arr[x-1] && arr[x] > arr[x+1];
            }
        };
        
        // output
        vector<int> res;
        for (auto &q: queries) {
            if (q[0] == 1) {
                int sum = query(0, 0, n-1, q[1], q[2]);
                sum -= isPeak[q[1]];
                if (q[1] != q[2])
                    sum -= isPeak[q[2]];
                res.push_back(sum);
            }
            else {
                int x = q[1], val = q[2];
                arr[x] = val;
                updatePeak(x);
                update(0, 0, n-1, x, isPeak[x]);
                if (x > 0) {
                    updatePeak(x-1);
                    update(0, 0, n-1, x-1, isPeak[x-1]);
                }
                if (x+1 < n) {
                    updatePeak(x+1);
                    update(0, 0, n-1, x+1, isPeak[x+1]);       
                }
            }
        }
        
        return res;
    }
};
