// Simple use hashtable
// O(NlogN)

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // goal: find the player which win all, and find lose exactly once
        // idea: use hashtable
        
        unordered_map<int, int> win, lose;
        
        for (auto &m : matches) {
            win[m[0]]++;
            lose[m[1]]++;
        }
        
        vector<vector<int>> res(2);
        
        for (auto &[k, v] : win) {
            if (!lose.count(k))
                res[0].push_back(k);
        }
        
        for (auto &[k, v] : lose) {
            if (v == 1)
                res[1].push_back(k);
        }
        
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        
        return res;
    }
};


// just one map
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // goal: find the player which win all, and find lose exactly once
        // idea: use hashtable
        
        map<int, int> lose;
        
        for (auto &m : matches) {
            if (!lose.count(m[0])) lose[m[0]] = 0;
            lose[m[1]]++;
        }
        
        vector<vector<int>> res(2);
        for (auto &[k, v] : lose) {
            if (v == 0)
                res[0].push_back(k);
            if (v == 1)
                res[1].push_back(k);
        }

        return res;
    }
};
