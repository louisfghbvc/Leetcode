// O(N^2). use array as map. use two sum stagery

class Solution {
public:
    const int mod = 1e9+7;
    int threeSumMulti(vector<int>& arr, int target) {
        int res = 0;
        int n = arr.size();
        for(int i = 0; i < n; ++i){
            int nt = target - arr[i];
            int mp[505] = {};
            for(int j = i+1; j < n; ++j){
                res += mp[nt - arr[j] + 200];
                res %= mod;
                mp[arr[j] + 200]++;
            }
        }
        return res;
    }
};

// O(n^2). enum all candidate.
// 4 case.
class Solution {
public:
    const int mod = 1e9+7;
    int threeSumMulti(vector<int>& arr, int target) {
        long res = 0;
        long mp[101] = {};
        for(int x: arr) mp[x]++;
        
        // 4 case.
        // 3*i == target
        // 2*i + j == target
        // i + 2*j == target
        // i + j + k == target
        for(int i = 0; i < 101; ++i){
            if(3*i == target) res += mp[i] * (mp[i]-1) * (mp[i]-2) / 6;
            for(int j = i+1, k = target - i - j; j < 101; ++j, --k){
                if(2*i + j == target) res += mp[i] * (mp[i]-1) * mp[j] / 2;
                if(i + 2*j == target) res += mp[i] * mp[j] * (mp[j]-1) / 2;
                if(k > j && k < 101) res += mp[i] * mp[j] * mp[k];
            }
        }
        return res % mod;
    }
};
