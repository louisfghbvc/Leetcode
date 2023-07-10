class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        // goal: return the sorted of occupied positions
        
        // idea: use the hashtable to record the index
        // simulate it
        
        map<int, int> cnt;
        for (int x: nums)
            cnt[x]++;
        
        int n = moveTo.size();
        for (int i = 0; i < n; ++i) {
            int &num = cnt[moveFrom[i]];
            if (moveFrom[i] == moveTo[i]) continue;
            cnt[moveTo[i]] += num;
            num = 0;
        }
        
        vector<int> idx;
        for (auto &[k, f]: cnt)
            if (f > 0)
                idx.push_back(k);
        return idx;
    }
};
