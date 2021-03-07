// O(N).

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n;){
            if(s[i] == '1'){
                while(i < n && s[i] == '1') i++;
                cnt++;
            }
            else i++;
        }
        return cnt <= 1;
    }
};
