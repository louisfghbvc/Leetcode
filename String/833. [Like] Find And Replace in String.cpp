// base on sorting. O(NlogN). worst O(N*N), replace up to linear.
// inplace modified.
// string replace, compare.
// build it from left to right. no need to calculate the diff

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<vector<int>> bind_ind;
        for(int i = 0; i < indices.size(); ++i)
            bind_ind.push_back({indices[i], i});
        // sort by increasing
        sort(bind_ind.rbegin(), bind_ind.rend());
        
        for(auto &ind: bind_ind){
            int s_i = ind[0], origin_i = ind[1];
            string source = sources[origin_i];
            string target = targets[origin_i];
            if(s.compare(s_i, source.size(), source) == 0)
                s.replace(s_i, source.size(), target);
        }
        
        return s;
    }
};
