// count zero nums. and jump back to i
// one pass.
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i){
            cnt = 0;
            bool ok = 0;
            while(i < nums.size() && !nums[i]){
                cnt++;
                i++;
                ok = 1;
            }
            if(ok && cnt < k) return 0;
            if(ok) i--;
        }
        return 1;
    }
};


// More clean.
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int fre = -1;
        bool flag = false;
        for(int x: nums){
            if(x) flag = true;
            if(flag){
                if(x){
                    if(fre >= 0 && fre < k) return false;
                    fre = 0;
                }
                else fre++;
            }
        }
        return true;
    }
};
