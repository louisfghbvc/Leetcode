class Solution {
public:
    
    template<int B=37>
    vector<bool> calHash1(vector<int>& parent, string s) {
        int n = parent.size();
        
        // init hash
        using hash_t = unsigned long long;
        vector<hash_t> powB(n+1, 1);
        for (int i = 1; i <= n; ++i)
            powB[i] = powB[i-1] * B;
        
        // build tree
        vector<vector<int>> tree(n);
        for (int i = 1; i < n; ++i) {
            tree[parent[i]].push_back(i);
        }
        
        vector<hash_t> ori(n), rev(n);
        using T = pair<hash_t, int>; // hash, len
        auto dfs = [&](auto& self, int u, int p=-1) -> T {
            // {aaa} {bb} a
            vector<T> tmp;
            for (int v: tree[u]) if (v != p) {
                tmp.emplace_back(self(self, v, u));
            }
            tmp.emplace_back(s[u]-'a', 1);
            
            int len = tmp.back().second;
            for (int i = tmp.size()-2; i >= 0; --i) {
                tmp[i].first *= powB[len];  
                tmp[i].first += tmp[i+1].first;
                len += tmp[i].second;
            }
            
            tmp[0].second = len;
            ori[u] = tmp[0].first;
            return tmp[0];
        };
        dfs(dfs, 0);
        
        auto dfs2 = [&](auto& self, int u, int p=-1) -> T {
            
            vector<T> tmp;
            //  {aaa} {ba} {a}           
            for (int v: tree[u]) if (v != p) {
                tmp.emplace_back(self(self, v, u));
            }
            tmp.emplace_back(s[u]-'a', 1);
            reverse(tmp.begin(), tmp.end());
            
            int len = tmp.back().second;
            for (int i = tmp.size()-2; i >= 0; --i) {
                tmp[i].first *= powB[len];  
                tmp[i].first += tmp[i+1].first;
                len += tmp[i].second;
            }
            
            tmp[0].second = len;
            rev[u] = tmp[0].first;
            return tmp[0];
        };
        dfs2(dfs2, 0);
        
        // output
        vector<bool> res(n);
        for (int i = 0; i < n; ++i) {
            // cout << ori[i] << ' ' << rev[i] << endl;
            res[i] = (ori[i]==rev[i]);
        }
        return res;
    }
    
    vector<bool> findAnswer(vector<int>& parent, string s) {
        // goal: find if dfs string is palindrome
        
        // idea:
        // build the tree 
        
        // two pass
        // one pass => build suf hash
        // one pass => build pre hash
        
        // dfs(x)
        // str = dfs(a) + dfs(b) + s[x]
        //        ab      cd        e
        //       s[x] + rev(dfs(b)) + rev(dfs(a))
        //         e        dc          ba
        
        // (aba)(ab)a
        
        // ori hash(1) = 37
        // ori hash(2) = 1
        
        // 37   + 1 + 0
        // 37*37^2 +  
        
        // rev hash(1) = 37
        // rev hash(2) = 37
        
        // 0 + 37 + 37
        // 0*37^2
        
        return calHash1<37>(parent, s);
    }
};
