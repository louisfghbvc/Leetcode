// Count in-degree and out-degree.
// because trust are all unique.
// if in-degree == N-1 and out-degree == 0, is town judge.
// trick, O(T+N)

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> cnt(N+1);
        for(const auto& e: trust){
            cnt[e[0]]--;
            cnt[e[1]]++;
        }
        for(int i = 1; i <= N; ++i){
            if(cnt[i] == N-1) return i;
        }
        return -1;
    }
};

// Solution 2 brute-force . O(T+N+T)
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> g[N+1];
        for(const auto& e: trust){
            g[e[0]].push_back(e[1]);
        }
        int jud = -1;
        for(int i = 1; i <= N; ++i){
            if(g[i].size() == 0) jud = i;
        }
        if(jud == -1) return -1;
        for(int i = 1; i <= N; ++i){
            if(i == jud) continue;
            bool ok = 0;
            for(const auto &v: g[i]){
                if(v == jud) ok = 1;
            }
            if(!ok) return -1;
        }
        return jud;
    }
};
