// idea2: simulate the process!! since erase number only once!

class Solution {
public:
    using ii = pair<int, int>;
    int totalSteps(vector<int>& nums) {
        // goal: calculate the steps
        // each time we remove all num[i-1] > num[i]
        
        // idea: stack -> wrong, 
        // 5 3 4 4 -> 3 values remove 
        // 5 7 -> 2 values remove
        // 5 7 11
        
        // idea2: simulate the process
        // O(NlogN), the value will disappear only once
        
        map<int, int> mp;
        vector<ii> to_del; // {(i, i+1)}
        
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            mp[i] = nums[i];
            if (i+1 < n && nums[i] > nums[i+1]) 
                to_del.emplace_back(i, i+1);
        }
        
        int ops = 0;
        while (to_del.size()) {
            ops++;
            
            vector<ii> nxt;
            for (auto &[i, j]: to_del)
                mp.erase(j);
            
            for (auto &[i, j]: to_del) {
                auto it = mp.find(i);
                if (it == mp.end() || it == prev(mp.end())) continue; // last or empty
                auto nxt_it = next(it);
                if (it->second > nxt_it->second)
                    nxt.emplace_back(it->first, nxt_it->first);
            }
            
            to_del = move(nxt);
        }
        
        return ops;
    }
};

// O(N), stack
