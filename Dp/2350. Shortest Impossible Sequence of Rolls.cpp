class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        // goal: find the shortest sequence that is not appear in rolls
        
        // idea: enumerate from length 1 to n
        // observe that the length at most 3 -> wrong
        
        // calculate the frequencies
        
        // maybe in the smaller range
        // guess the length -> how to guess???
        // each length, combination: k^length
        
        // O(len*n)
//         for (int len = 2; len <= res; ++len) {
//             vector<int> ndp; // length ending at index i
            
//             unordered_set<int> st;
//             for (int idx: dp) {
//                 if (st.size() == k) // valid index !!!
//                     ndp.push_back(idx);
//                 else
//                     st.insert(rolls[idx]);
//             }
            
//             dp = move(ndp);
//             if (st.size() != k)
//                 return len;
//         }
         
        
        // when size is k, restart!
        int len = 1; // missing
        vector<bool> vis(k+1);
        int cnt = 0;
        for (int x: rolls) {
            if (!vis[x]) {
                vis[x] = 1;
                cnt++;
                if (cnt == k) {
                    vis = vector<bool>(k+1);
                    cnt = 0;
                    len++;
                }
            }
        }
        
        return len;
    }
};
