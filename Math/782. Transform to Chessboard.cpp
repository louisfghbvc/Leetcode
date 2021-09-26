// first think 1D [0, 1, 1, 1, 0, 0] and we want to know the least cost to make it [0, 1, 0, 1, 0, 1] or [1, 0, 1, 0, 1, 0].
// too hard, logic and so many case.
// hash to int32: A = 1010. 5 = 0101
// and dimension is independence...
// [0, 1, 1, 1, 0] only has one candidate [1, 0, 1, 0, 1]

class Solution {
public:
    int helper(unordered_map<int, int> cnt, int n){
        // only two case, why?
        // since ans grid only 2 case. 
        if(cnt.size() != 2) return -1;
        
        vector<int> key;
        for(auto &[k, v]: cnt) key.push_back(k);
        
        int k1 = key[0], k2 = key[1];
        
        // 2 key must be same number, or odd
        if(!(cnt[k1] == n/2 && cnt[k2] == (n+1)/2) && !(cnt[k1] == (n+1)/2 && cnt[k2] == n/2)) return -1;
        
        int mask = (1<<n)-1;
        // 2 key must be alternate
        if((k1 ^ k2) != mask) return -1;
        
        int ones = __builtin_popcount(k1);
        int res = INT_MAX;
        if(n % 2 == 0 || ones * 2 < n) // start with 0, since 1010...1(0101010), ones smaller 
            res = min(res, __builtin_popcount(k1 ^ 0xAAAAAAAA & mask) / 2);
        if(n % 2 == 0 || ones * 2 > n)
            res = min(res, __builtin_popcount(k1 ^ 0x55555555 & mask) / 2);
        
        return res;
    }
    
    int movesToChessboard(vector<vector<int>>& board) {
        unordered_map<int, int> mp;
        for(auto &r: board){
            int hash = 0;
            for(auto &c: r)
                hash = hash*2 + c;
            mp[hash]++;
        }
        int row = helper(mp, board.size());
        if(row == -1) return -1;
        
        mp.clear();
        for(int j = 0; j < board.size(); ++j){
            int hash = 0;
            for(int i = 0; i < board.size(); ++i)
                hash = hash*2 + board[i][j];
            mp[hash]++;
        }
        
        int col = helper(mp, board.size());
        if(col == -1) return -1;
        
        return col + row;
    }
};
