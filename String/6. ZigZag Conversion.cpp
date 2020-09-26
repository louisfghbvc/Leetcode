// A boring problem.
// O(N).

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> A(numRows);
        bool down = 0;
        for(int i = 0, r = 0; i < s.size(); ++i){
            if(!r || r == numRows-1) down ^= 1;
            A[r] += s[i];
            if(down) r++;
            else r--;
        }
        string res = "";
        for(auto &r: A) res += r;
        return res;
    }
};
