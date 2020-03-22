//Kmp table. 56ms 20.9MB
class Solution {
public:
    int kmp_table(string s){
        vector<int> res(s.size(), 0); //every index max pre and suf length
        int j = 0;
        for(int i = 1; i < s.size();){
            if(s[i] == s[j]){
                res[i] = ++j;
                i++;
            }
            else{
                if(j != 0)
                    j = res[j - 1]; //tricky
                else
                    i++;
            }
        }
        return res.back();
    }
    string longestPrefix(string s) {
        return s.substr(0, kmp_table(s));
    }
};

//string view very fast and easy. but this should use kmp to solve, 588ms 14.9MB
class Solution {
public:
    string longestPrefix(string s) {
        string_view sv(s);
        string ans = "";
        for(int i = 0, j = s.size() - 1; i < s.size() - 1; ++i, --j){
            string_view a = sv.substr(0, i + 1);
            string_view b = sv.substr(j);
            if(a == b)
                ans = a;
        }
        
        return ans;
    }
};
