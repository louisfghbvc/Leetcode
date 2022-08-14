class Solution {
public:
    vector<int> diStringMatch(string s) {
        // goal: build the res that satisfied the string s
        
        // idea: build from left to right
        // I put smallest number
        // D put greatest number
        // TC: O(N), SC: O(N)
        
        // 0 1 2 3 4
        //  I.    D
        
        int n = s.size();
        
        vector<int> res(n+1);
        int lo = 0, hi = n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'I')
                res[i] = lo++;
            else
                res[i] = hi--;
        }
        res.back() = hi;
        
        return res;
    }
};

// O(N), stack
class Solution {
public:
    vector<int> diStringMatch(string s) {
        
        // idea: build from left to right
        // if we meet D, push into stack
        // TC: O(N), SC: O(N)
        
        vector<int> res, st;
        
        for (int i = 0; i <= s.size(); ++i) {
            st.push_back(i);
            if (i == s.size() || s[i] == 'I') {
                while (st.size()) {
                    res.push_back(st.back());
                    st.pop_back();
                }
            }
        }
        
        return res;
    }
};
