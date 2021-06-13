// Well... this pass == O((N/2)*2^(N/2)log2^(N/2)).
class Solution {
public:
    unordered_map<int, pair<int, int>> bit;
    
    pair<int, int> dfs(int p, int p1, int p2){
        if(!(p>>p1&1) || !(p>>p2&1)) return {0, 0};
        
        if(bit.count(p)) return bit[p];
        
        vector<int> arr;
        for(int i = 27; i >= 0; --i) if(p >> i & 1) arr.push_back(1<<i);
        
        int n = arr.size();
        int n2 = n/2;
        int mx = 0, mn = 1e9;
        for(int S = 0; S < 1<<n2; ++S){
            int sb = 0;
            for(int i = 0; i < n2; ++i){
                if(arr[n - i - 1] == (1<<p1) || arr[n - i - 1] == (1<<p2))
                    sb |= arr[n - i - 1];
                else if(arr[i] == (1<<p1) || arr[i] == (1<<p2))
                    sb |= arr[i];  
                else if(S >> i & 1){ // right win
                    sb |= arr[n - i - 1];
                }
                else 
                    sb |= arr[i]; // left win
            }
            if(n & 1)
                sb |= arr[n2];
            auto tmp = dfs(sb, p1, p2);
            
            mx = max(mx, tmp.second+1);
            mn = min(mn, tmp.first+1);
        }
        return bit[p] = {mn, mx};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int mask = (1<<n)-1;
        --firstPlayer, --secondPlayer;
        auto [mn, mx] = dfs(mask, firstPlayer, secondPlayer);
        return {mn, mx};
    }
};

// More fast. BF.
class Solution {
public:
    int min_r = INT_MAX, max_r = INT_MIN;
    void dfs(int mask, int round, int i, int j, int first, int second) {
        if (i >= j)
            dfs(mask, round + 1, 0, 27, first, second); // next round
        else if ((mask & (1 << i)) == 0)
            dfs(mask, round, i + 1, j, first, second);
        else if ((mask & (1 << j)) == 0)
            dfs(mask, round, i, j - 1, first, second);
        else if (i == first && j == second) {
            min_r = min(min_r, round);
            max_r = max(max_r, round);
        }
        else {
            if (i != first && i != second)
                dfs(mask ^ (1 << i), round, i + 1, j - 1, first, second);
            if (j != first && j != second)
                dfs(mask ^ (1 << j), round, i + 1, j - 1, first, second);
        }
    }
    vector<int> earliestAndLatest(int n, int first, int second) {
        dfs((1 << n) - 1, 1, 0, 27, min(first, second) - 1, max(first, second) - 1);
        return {min_r, max_r};
    }
};
