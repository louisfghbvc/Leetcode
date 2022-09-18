class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // goal: maximum of matching, one-one-match
        // idea: sort players, and trainer use the set
        
        // O(nlogn+mlogm+nlogm)
        
        sort(players.begin(), players.end());
        multiset<int> st(trainers.begin(), trainers.end());
        
        
        int cnt = 0;
        for (int x: players) {
            auto it = st.lower_bound(x);
            if (it != st.end()) {
                cnt++;
                st.erase(it);
            }
        }
        
        return cnt;
    }
};
