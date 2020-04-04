//Just count sum, and map it
class Solution {
public:
    int cnt(int x){
        int ans = 0;
        while(x > 0){
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int mx = 0;
        for(int i = 1; i <= n; ++i){
            mx = max(++mp[cnt(i)], mx);
        }
        int res = 0;
        for(auto x: mp){
            if(x.second == mx) res++;
        }
        return res;
    }
};
