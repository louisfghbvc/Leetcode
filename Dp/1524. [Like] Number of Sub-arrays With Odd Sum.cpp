// think by myself, dp
// cnt zero con.
// so when odd need to insert a new value.
// O(N).
class Solution {
public:
    int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        for(int &x: arr) x = x%2;
        long ans = 0, con = 0;
        vector<int> dp;
        for(int i = 0; i < arr.size(); ++i){
            int cur = 1;
            if(arr[i] == 1){
                cur += con;
                if(dp.size() >= 2) cur += dp[dp.size()-2];
                dp.push_back(cur);
                con = 0;
            }
            else{
                con++;
            }
            if(dp.size()) ans += dp.back();
        }
        return ans % mod;
    }
};

// accumulate. O(N). like dp.
// The magic is odd will change even and odd.
// so... keep two value even and odd.
// when odd. swap because odd will become even.
// now add odd. to total
// actally is very like previos sol. but some trick optimal.
class Solution {
public:
    int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0, even = 0, odd = 0;
        for(int &x: arr){
            if(x % 2){
                swap(odd, even);
                odd++;
            }
            else even++;
            ans = (ans + odd) % mod;
        }
        return ans;
    }
};
