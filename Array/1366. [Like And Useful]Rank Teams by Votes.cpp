//12ms 10.3MB use lambda fast
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string res(votes[0]);
        const int n = res.size();
        vector<vector<int>> rank(26, vector<int>(n, 0));
        
        for(const string& v: votes){
            for(int i = 0; i < n; ++i){
                rank[v[i] - 'A'][i]++;
            }
        }
        
        sort(res.begin(), res.end(), [&](const char&x, const char&y){
            return rank[x - 'A'] > rank[y - 'A'] || rank[x - 'A'] == rank[y - 'A'] && x < y;
        });
        
        
        return res;
    }
};
