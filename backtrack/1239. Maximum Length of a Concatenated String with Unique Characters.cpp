//444ms 47.4MB
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
