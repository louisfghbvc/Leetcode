//string view very fast and easy. but this should use kmp to solve
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
