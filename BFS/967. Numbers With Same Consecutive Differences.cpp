// level by level, bfs.
// WA 2 times. because some check. x == 0 and duplicate. K == 0
// O(N*2^N) 0ms. 7.5MB
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(int i = 1; i < N; ++i){
            vector<int> nxt;
            for(auto &x: res){
                int d = x%10;
                if(x && d+K < 10) nxt.push_back(x*10+d+K);
                if(x && K && d-K >= 0) nxt.push_back(x*10+(d-K));
            }
            res = nxt;
        }
        return res;
    }
};
