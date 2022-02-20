// O(N), O(1) space
// simulate. greedy.
// simple constructive alo

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res = "";
        
        vector<int> fre(26);
        for(char c: s)
            fre[c-'a']++;

        bool ok = true;
        int repeat = 0;
        int ch = -1;
        
        while(ok){
            ok = false;
            
            for(int i = 25; i >= 0; --i){
                if(!fre[i]) continue;
                if(ch == -1 || ch != i){
                    ch = i;
                    ok = true;
                    repeat = 1;
                    break;
                }
                else if(ch == i && repeat < repeatLimit){
                    ok = true;
                    repeat++;
                    break;
                }
            }

            if(ok){
                fre[ch]--;
                res.push_back('a' + ch);
            }
        }
        
        return res;
    }
};
