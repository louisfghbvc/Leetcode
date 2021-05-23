class Solution {
public:
    bool checkZeroOnes(string s) {
        int cnt[2] = {};
        int mx[2]= {};
        for(char c: s){
            if(c == '0'){
                cnt[1] = 0;
                cnt[0]++;
                mx[0] = max(mx[0], cnt[0]);
            }
            else{
                cnt[0] = 0;
                cnt[1]++;
                mx[1] = max(mx[1], cnt[1]);
            }
        }
        return mx[1] > mx[0];
    }
};
