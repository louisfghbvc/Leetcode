// Enum O(2^N).
class Solution {
public:
    
    int conv(string &s){
        int res = 0;
        for(char c: s)
            res = res * 2 + c-'0';
        return res;
    }
    
    string conv(int x, int n){
        string res = "";
        while(n--){
            res.push_back('0' + x%2);
            x >>= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<bool> vis(1<<n);
        for(auto &s: nums){
            vis[conv(s)] = 1;
        }
        
        for(int i = 0; i < vis.size(); ++i){
            if(!vis[i]) return conv(i, n);
        }
        return "";
    }
};

// Cantor's Diagonalization, each position 1 diff. so that after n. always different.
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res(nums.size(), '0');
        // set res only 1 differ bit
        for(int i = 0; i < nums.size(); ++i){
            res[i] = nums[i][i] ^ 1;
        }
        return res;
    }
};
