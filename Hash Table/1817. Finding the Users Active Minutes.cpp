// Simple hash table. can do O(N)

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> mt(k);
        unordered_map<int, set<int>> g;
        for(auto &lg : logs){
            g[lg[0]].insert(lg[1]);
        }
        for(auto &[k, st]: g){
            mt[st.size()-1]++;
        }
        return mt;
    }
};
