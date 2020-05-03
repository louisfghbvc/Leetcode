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
