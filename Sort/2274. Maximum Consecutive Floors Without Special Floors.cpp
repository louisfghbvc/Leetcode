// Time: O(NlogN), Space: O(N)

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        // goal: find the maxConsecutive range that don;t have special floor
        // idea: use a map -> like old driver tree
        // try to seperate the map, after that calculate the distance
        
        map<int, int> mp; // left -> right
        mp[bottom] = top; 
        
        auto split = [&](int x) { // split mp to [l, x-1], [x+1, r]
            auto it = prev(mp.upper_bound(x)); // never reach the mp.begin()
            auto [l, r] = *it;
            mp.erase(it);
            if (l <= x-1)
                mp.insert({l, x-1});
            if (x+1 <= r)
                mp.insert({x+1, r});
        };
        
        // O(Nlogn)
        for (auto &p: special) {
            split(p);
        }
        
        int res = 0;
        for (auto &[l, r]: mp) {
            res = max(res, r-l+1);
        }
        
        return res;
    }
};

// Solution2, just use give array, no need to split 
