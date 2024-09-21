class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // goal: print the array such that sort by string

        // n = 10
        // 1 10 2 3 4 5 6 8 9     

        // idea:
        // generate and sort => SC: O(n), TC: O(nlogn)
        
        // think about when we start from 1 - n
        // there is a pattern
        // 1  2 3 4 5 6 7 8 9
        // 10 20
        // 11 ..
        // ..
        // 19 29
        // 100
        // 101
        // ...
        // 199

        // we will do all leading 1 to 9
        // iterate from length 1, length 2 .. until greater then n

        // after looking the solution, we can just using dfs!!!
        //    1 
        // 10  ... 19
        // 100...
        
        vector<int> res;

        auto dfs = [&](auto &self, int x) -> void {
            if (x > n) return;
            res.push_back(x);
            for (int d = 0; d < 10; ++d) {
                self(self, x*10 + d);
            }
        };

        for (int i = 1; i <= 9; ++i)
            dfs(dfs, i);

        return res;
    }
};
