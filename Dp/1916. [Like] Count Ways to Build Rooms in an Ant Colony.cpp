// hard to think math...
// O(N). so consider the total case that say .e.g 2.
// tot N! = 5!. and we need to divide 5, divide 2, divide 2.
// since that 5 is not true, there is only 1 that can pass. say subtree 1 is 5. node 1 should build then build others.

class Solution {
public:
    const int mod = 1e9+7;
    
    long fpow(long a, long b){
        long res = 1;
        while(b){
            if(b&1) res = res*a%mod;
            a = a*a%mod;
            b >>= 1;
        }
        return res;
    }
    
    long modinv(long x){
        return fpow(x, mod-2);
    }
    
    int n;
    vector<vector<int>> g;
    vector<int> sub_tree;
    
    // calculate the each node subtree size
    void dfs(int u, int p = -1){
        for(int v: g[u]){
            if(v != p){
                dfs(v, u);
                sub_tree[u] += sub_tree[v];
            }
        }
        sub_tree[u]++;
    }
    
    int waysToBuildRooms(vector<int>& prevRoom) {
        n = prevRoom.size();
        g = vector<vector<int>>(n);
        sub_tree.resize(n);
        
        for(int i = 1; i < n; ++i){
            g[prevRoom[i]].push_back(i);
        }
        
        // total numbers of ways
        long tot = 1;
        for(int i = 2; i <= n; ++i)
            tot = tot * i % mod;
        
        dfs(0);
        
        long div = 1;
        for(int i = 0; i < n; ++i){
            div = div * modinv(sub_tree[i]) % mod;
        }
        
        return tot * div % mod;
    }
};
