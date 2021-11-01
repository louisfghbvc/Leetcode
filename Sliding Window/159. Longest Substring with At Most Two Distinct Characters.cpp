class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        // assume ascii letters
        vector<int> fre(128);
        int size = 0;
        
        // idea: maintain the window size size at most 2
        
        int res = 0;
        for(int r = 0, l = 0; r < s.size(); ++r){
            if(++fre[s[r]] == 1) size++;
            while(size > 2){
                if(--fre[s[l]] == 0) size--;
                l += 1;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
