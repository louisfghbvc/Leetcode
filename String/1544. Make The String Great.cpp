// O(N). trick. use back(). when abs() == 32. then delete.
// because each pair only use once. like brackets problem.
class Solution {
public:
    string makeGood(string s) {
        string res;
        for(auto &c: s){
            if(res.size() && abs(res.back()-c) == 32){
                res.pop_back();
            }
            else res += c;
        }
        return res;
    }
};

// BF. simulate
class Solution {
public:
    string makeGood(string s) {
        string res = s;
        while(1){
            string nt = "";
            bool ok = false;
            int n = res.size();
            for(int i = 0; i < n; ++i){
                if(i + 1 == n){
                    nt += res[i];
                    continue;
                }
                char a = tolower(res[i]);
                char b = tolower(res[i+1]);
                if(a == b && res[i] != res[i+1]){
                    ok = true;
                    i++;
                }
                else{
                    nt += res[i];
                }
            }
            // cout << nt << endl;
            res = nt;
            if(!ok) break;
        }
        
        return res;
    }
};
