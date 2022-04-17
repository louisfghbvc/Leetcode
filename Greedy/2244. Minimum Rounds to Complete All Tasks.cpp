class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        
        // goal: each round can finish 2 or 3 tasks
        // note: the order doesn't matter
        // idea: compute the consective task length
        // if mod 3 == 0: use 3
        // if mod 3 == 1: use 2 two times
        
        int res = 0;
        int n = tasks.size();
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && tasks[j] == tasks[i]) j++;
            
            int len = j-i;
            if (len % 3 == 0) {
                res += len / 3;
            }
            else if (len % 3 == 2) {
                res += len / 3 + 1;
            }
            else {
                if (len == 1) return -1;
                res += 2;
                len -= 4;
                res += len / 3;
            }
        }
        
        return res;
    }
};
