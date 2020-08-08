// Boring string problem.
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        int n = S.size();
        string t = "";
        for(int i = 0; i< n; ++i){
            if(S[i] != '-'){
                if(islower(S[i])) S[i] = S[i]-'a'+'A';
                t += S[i];
            }
        }
        string c = "";
        for(int i = t.size()-1; i >= 0; --i){
            c += t[i];
            if(c.size() == K){
                res += '-' + c;
                c = "";
            }
        }
        if(c.size()){
            res += '-' + c;
        }
        reverse(res.begin(), res.end());
        if(res.size()) res.pop_back();
        return res;
    }
};
