// O(N^2). Stupid simulate.

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> res;
        int sz = rounds.size();
        int cnt[105] = {};
        cnt[rounds[0]]++;
        for(int i = 0; i+1 < sz; ++i){
            for(int j = rounds[i]+1; ; ++j) {
                if(j > n) j = 1;
                cnt[j]++;
                if(j == rounds[i+1]) break;
            }
        }
        int mx = 0;
        for(int i = 1; i <= 100; ++i) mx = max(mx, cnt[i]);
        // cout << mx << "\n";
        for(int i = 1; i <= 100; ++i){
            if(cnt[i] == mx) res.push_back(i);
        }
        return res;
    }
};

// O(N).
