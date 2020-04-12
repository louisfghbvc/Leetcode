class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans(queries.size(), 0);
        vector<int> p(m+1, 0);
        for(int i = 0; i < m; ++i){
            p[i]=i+1;
        }
        for(int i = 0; i < queries.size(); ++i){
            int num = queries[i];
            ans[i] = (find(p.begin(), p.end(), queries[i]) - p.begin());
            p.erase(p.begin() + ans[i]);
            p.insert(p.begin(), num);
        }
        return ans;
    }
};
