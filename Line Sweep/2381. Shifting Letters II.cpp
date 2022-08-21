class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // goal: find the final string after apply shifts
        // idea: line sweep
        // each operation: 
        // if dir = 1, add[l] + 1, add[r] -= 1
        // else arr[l] -= 1, add[r] += 1 
        
        //  0 ....  5 6
        // +1         -1
        //. 1 1 ... 1 0
        
        int n = s.size();
        
        vector<int> ops(n+1);
        
        // O(shifts.length)
        for (auto &op: shifts) {
            int l = op[0], r = op[1], dir = op[2];
            if (dir) {
                ops[l]++;
                ops[r+1]--;
            }
            else {
                ops[l]--;
                ops[r+1]++;
            }
        }
        
        // O(N)
        for (int i = 1; i < n; ++i)
            ops[i] += ops[i-1];
        
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            c += ops[i];
            c = (c % 26 + 26) % 26;
            s[i] = 'a'+c;
        }
        
        return s;
    }
};
