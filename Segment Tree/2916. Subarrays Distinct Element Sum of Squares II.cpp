class Solution {
public:

    struct SegmentTree {
        SegmentTree(int n) {
            tree.resize(4*n);
            lazyTag.resize(4*n);
        }

        void push(long id, int l, int r) {
            if (l == r) return;
            if (!lazyTag[id]) return;
            long inc = lazyTag[id];
            int m = (l+r)/2;
            lazyTag[id*2+1] += inc;
            tree[id*2+1] += inc * (m-l+1);

            lazyTag[id*2+2] += inc;
            tree[id*2+2] += inc * (r-(m+1)+1);
            lazyTag[id] = 0;
        }

        long query(long id, int l, int r, int ll, int rr) {
            push(id, l, r);
            if (ll <= l && r <= rr) return tree[id];
            if (l > rr || r < ll) return 0;
            int m = (l+r)/2;
            return query(id*2+1, l, m, ll, rr) + query(id*2+2, m+1, r, ll, rr);
        }

        void update(long id, int l, int r, int ll, int rr, int val) {
            push(id, l, r);
            if (l > rr || r < ll) return;
            if (ll <= l && r <= rr) {
                tree[id] += val * (r-l+1);
                lazyTag[id] += val; // inc
                return;
            }
            int m = (l+r)/2;
            update(id*2+1, l, m, ll, rr, val);
            update(id*2+2, m+1, r, ll, rr, val);
            tree[id] = tree[id*2+1] + tree[id*2+2];
        }

        vector<long> tree;
        vector<long> lazyTag;
    };

    int sumCounts(vector<int>& nums) {
        // goal: find the all subarray distinct number square sum
        // idea:
        // TC: O(n^2) -> TLE

        // consider dp[i]: ending at index i, sum of distinct from [j:i], j=0~i-1
        // dp[i] = dp[i-1] + range update of distinct array (not dp)
        // we will change (j,i) increase by 1 -> range update
        // x^2 => (x+1)^1, increase 2x+1
        // [3, 1,2,1] 
        //  2  1
        //  3  2 1
        //  3  2 2 1

        int n = nums.size();
        int mod = 1e9+7;

        SegmentTree tree(n); 
        
        long ans = 0;
        long tot = 0;
        unordered_map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            int j = -1;
            if (pos.count(nums[i]))
                j = pos[nums[i]];
            // range value increase by 1
            tot += tree.query(0, 0, n-1, j+1, i) * 2 % mod + i-j;
            tot %= mod;
            ans = (ans + tot) % mod;
            tree.update(0, 0, n-1, j+1, i, 1);
            pos[nums[i]] = i;
        }

        return ans;
    }
};
