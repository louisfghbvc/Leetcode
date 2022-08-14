// reverse the number when meets 'I'
// greedy

class Solution {
public:
    string smallestNumber(string pattern) {
        // goal: build the smallest number match the pattern
        // idea:
        // reverse the number between I
        
        // 1 2 3 4 5 6 7 8 9
        // I I I D I D D D
        // 1 2 3 (4, 5) (6, 7, 8, 9)
        
        int n = pattern.size()+1;
        
        string res, st;
        
        for (int i = 0; i <= pattern.size(); ++i) {
            st.push_back('1'+i);
            if (i == pattern.size() || pattern[i] == 'I') {
                while (st.size()) {
                    res += st.back();
                    st.pop_back();
                }
            }
        }
        
        return res;
    }
};


// backtracking
class Solution {
public:
    string smallestNumber(string pattern) {
        // goal: build the smallest number match the pattern
        // idea:
        // backtracking all number, for each number
        // try to check if is valid or not
        
        // TC: O(n*n!)
        
        int n = pattern.size()+1;
        
        string s;
        string res(n, '9');
        auto dfs = [&](const auto &self, int cnt, int vis) {
            if (cnt == n) {
                // match the pattern
                
                bool ok = true;
                for (int i = 0; i+1 < n && ok; ++i) {
                    if ((s[i] < s[i+1]) && (pattern[i] == 'D')) ok = false;
                    if ((s[i] > s[i+1]) && (pattern[i] == 'I')) ok = false;
                }
                if(ok)
                    res = min(s, res);
                return;
            }
            
            for (int d = 1; d <= 9; ++d) {
                if (vis >> d & 1) continue;
                s.push_back('0'+d);
                self(self, cnt+1, vis|(1<<d));
                s.pop_back();
            }
            
        };
        
        dfs(dfs, 0, 0);
        
        return res;
    }
};
