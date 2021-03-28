// O(N). Observe Pattern. Rule based

class Solution {
public:
    string originalDigits(string s) {
        vector<string> pat = {"zero", // z
                              "one", // o
                              "two", // w
                              "three", // h
                              "four", // f
                              "five", // v
                              "six", // x
                              "seven", // s
                              "eight", // g
                              "nine"}; // i
        string res = "";
        int cnt[10] = {};
        
        for(char c: s){
            if(c == 'z') cnt[0]++;
            if(c == 'w') cnt[2]++;
            if(c == 'x') cnt[6]++;
            if(c == 's') cnt[7]++; // 7-6
            if(c == 'g') cnt[8]++;
            if(c == 'v') cnt[5]++; // 5-7
            if(c == 'f') cnt[4]++; // 4-5
            if(c == 'h') cnt[3]++; // 3-8
            if(c == 'i') cnt[9]++; // 9-5-6-8
            if(c == 'o') cnt[1]++; // 1-0-2-4
        }
        cnt[7] -= cnt[6];
        cnt[5] -= cnt[7];
        cnt[4] -= cnt[5];
        cnt[3] -= cnt[8];
        cnt[9] -= cnt[5]+cnt[6]+cnt[8];
        cnt[1] -= cnt[0]+cnt[2]+cnt[4];
        
        for(int i = 0; i < 10; ++i)
            res += string(cnt[i], '0'+i);
        
        return res;
    }
};
