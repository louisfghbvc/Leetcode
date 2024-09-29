class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // goal: we need to find the kth letter
        // k is very big
        // operations[0] => no change
        // operations[1] => change
        
        // idea:
        // divide and conquer?
        
        // k = 5
        //   a  => len = 1
        //  / \
        // aa ab => len = 2 (using op[i])
        // ....
        //       => len => 2^n
        // j at most 50
        
        
        // consider
        // j = 2
        //      a            => 0
        // /         \
        // aa         ab     => 1
        // /   \       | \ 
        // aaaa aabb  abab abbc => 2
        // 
        //  8
        
        // k=3 => 
         
        // k = 10
        
        //. length = 16
        //  j = 8
        
        auto dfs = [&](auto& self, long long i, int j) -> char {
            // cout << i << ' ' << j << endl;
            if (i <= 1) return 'a';
            
            // in the left
            long prev = 1LL<<(j-1);
            if (i <= prev) return self(self, i, j-1);
                        
            // changed
            if (operations[j-1]) {
                int id = self(self, i-prev, j-1) - 'a';
                return 'a' + ((id + 1) % 26);
            }
            else {
                return self(self, i-prev, j-1);
            }
        };
        
        return dfs(dfs, k, min(50, (int)operations.size()));
    }
};
