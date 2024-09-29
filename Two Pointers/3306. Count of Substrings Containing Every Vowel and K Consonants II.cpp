class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        // goal: count the substring will have aeiou and k others letter
        
        // idea:
        // two pointers?
        
        // k=1
        // "aeioub" 
        
        // consider F(x) => number of substring at most x consonants
        // 
        
        // record the cnt about aeiou
        // convert to 012345
        
        // k = 1
        //  0123450
        // "baeiouc"
        //       j 
        
        // idea2:
        // using prefix sum, for each index, using binary search to find the first match and last match
        // need to find the number of substring which cnt is between 0~k
        // WA ...
        
        //    l     r
        //  0 0 1 2 3 0
        //    
        // 
        
        string v = "aeiou";
        int n = word.size();
        
        using T = array<long, 6>;
        vector<T> pre(n+1, T{});
        for (int i = 0; i < n; ++i) {
            pre[i+1] = pre[i];
            pre[i+1][v.find(word[i])+1]++;
        }
        
        // helper function at least x operations
        auto helper = [&](int x) -> long {
            if (x < 0) return 0;
            
            auto ok = [&](T& val) {
                return val[1]>0 && val[2]>0 && val[3]>0 && val[4]>0 && val[5]>0;
            };
            
            T cur{};
            long ans = 0;
            for (int r = 0, l = 0; r < n; ++r) {
                cur[v.find(word[r])+1]++;
                while (cur[0] > x) {
                    cur[v.find(word[l])+1]--;
                    l++;
                }
                if (ok(cur)) {
                    ans += getMax(l, r) - l + 1;
                }
            }
            return ans;
        };
        
        
        return helper(k) - helper(k-1);
    }
};
