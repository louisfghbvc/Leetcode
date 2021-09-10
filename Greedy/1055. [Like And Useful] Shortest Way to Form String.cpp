// Binary Search, Just greedy see this pic https://leetcode.com/problems/shortest-way-to-form-string/discuss/309404/C%2B%2B-with-picture-greedy
class Solution {
public:
    int shortestWay(string source, string target) {
        vector<int> idx[26];
        for(int i = 0; i < source.size(); ++i){
            idx[source[i] - 'a'].push_back(i);
        }
        
        int cnt = 1;
        for(int i = 0, j = -1; i < target.size();){
            auto &cur = idx[target[i] - 'a'];
            if(cur.empty()) return -1;
            auto p = upper_bound(cur.begin(), cur.end(), j);
            if(p == cur.end()){
                j = -1;
                cnt++;
            }
            else{
                j = *p;
                i++;
            }
        }
        
        return cnt;
    }
};


// O(M + N). Use extra space. record the smallest position
class Solution {
public:
    int shortestWay(string source, string target) {
        int n = source.size(), m = target.size();
        
        // mapping, idx[i][char] = i, next position
        vector<vector<int>> idx(n);
        idx[n-1].resize(26, -1);
        idx[n-1][source[n-1] - 'a'] = n-1;
        
        // do from backward.
        for(int i = n-2; i >= 0; --i){
            idx[i] = idx[i+1];
            idx[i][source[i] - 'a'] = i;
        }
        
        int cnt = 0;
        int i = 0;
        for(char c: target){
            // exist this char?
            if(idx[0][c - 'a'] < 0) return -1;
            
            // next not exist
            if(idx[i][c - 'a'] < 0){
                cnt++;
                i = 0;
            } 
            
            // jump next position
            i = idx[i][c - 'a'] + 1;
            if(i == n){
                i = 0;
                cnt++;
            }
        }
        
        return cnt + (i!=0);
    }
};
