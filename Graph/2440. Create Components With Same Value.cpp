class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        // goal: maxmimum edge can delete, such that each connected component value sum is the same
        // idea: ?
        // observation: sum % value == 0 
        // observe: value are possible divisor of sum
        // observe: child is either all split, or all together
        
        //  o 
        // / \
        // o  o
        // /\. /\
        // o o o o
        
        int n = nums.size();
        vector<vector<int>> tree(n);
        vector<int> ind(n);
        for (auto &e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
            ind[e[0]]++;
            ind[e[1]]++;
        }
        
        int tot = accumulate(nums.begin(), nums.end(), 0);
        vector<int> val;
        for (int i = 1; i*i < tot; ++i) {
            if (tot % i == 0) {
                val.push_back(i);
                if (tot / i != i)
                    val.push_back(tot/i);
            }
        }
        sort(val.begin(), val.end());
        
        auto helper = [&](int x) {
            bool flag = false;
            int ans = 0;
            auto dfs = [&](auto &self, int u, int p=-1) -> int { // sum of child values 
                if (flag) {
                    ans = 0;
                    return 0;
                }
                int sum = 0;
                bool gather = false;
                vector<int> tmp;
                for (int v: tree[u]) if (v != p) {
                    int child = self(self, v, u);
                    tmp.push_back(child);
                    if (child < x) gather = true;
                }
                sum += nums[u];
                if (gather)
                    sum += accumulate(tmp.begin(), tmp.end(), 0);
                if (sum == x) ans++;
                if (sum > x) flag = 1;
                return sum;
            };
            dfs(dfs, 0);
            if (!flag) return ans;
            return 0;
        };
        
        int ans = 0;
        for (int x: val)
            ans = max(ans, helper(x));
        return ans-1;
    }
    
};
