//4ms 9.5MB
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int mx = 0;
        vector<int> dp = {0};
        for(auto s : arr){
            int a = 0;
            for(char c : s)
                a |= (1 << (c - 'a'));
            int n = __builtin_popcount(a);
            if(n < s.size()) continue;
            
            for(int i = dp.size() - 1; i >= 0; --i){
                int pre = dp[i];
                if(pre & a) continue;
                dp.push_back(pre | a);
                mx = max(mx, __builtin_popcount(pre | a));
            }
        }
        return mx;
    }
};
//444ms 47.4MB
/*
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int mx = 0;
        for(int i = 0; i < (1<<n); ++i){
            vector<bool> vis(26, 0);
            int tmp = 0;
            for(int j = 0; j < n; ++j){
                if(i & (1<<j)){
                    tmp += arr[j].size();
                    for(int k = 0; k < arr[j].size(); ++k){
                        if(vis[arr[j][k] - 'a']){
                            j = n;
                            tmp = 0;
                            break;
                        }
                        vis[arr[j][k] - 'a'] = true;
                    }
                }
            }
            mx = max(mx, tmp);
        }
        return mx;
    }
};
*/
