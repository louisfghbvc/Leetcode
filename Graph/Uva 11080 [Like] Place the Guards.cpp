// DFS O(N). minimum sub color, and color must can not be zero.
// many connected component, add all.

#include <bits/stdc++.h>
#define N 205
using namespace std;

vector<int> g[N];
int vis[N];
int c1, c2;

bool dfs(int u, int c){
    if(vis[u]) return c == vis[u]; 
    vis[u] = c;
    if(vis[u] == 1) c1++;
    else c2++;
    for(auto &v: g[u]){
        if(!dfs(v, 3-c)) return false;
    }
    return true;
}

int main()
{
    int t, v, e;
    cin >> t;
    while(t--){
        cin >> v >> e;
        for(int i = 0; i < v; ++i) g[i].clear();
        memset(vis, 0, sizeof vis);
        
        for(int i = 0; i < e; ++i){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bool ok = 1;
        int ans = 0;
        for(int i = 0; i < v; ++i){
            if(!vis[i]) {
                c1 = c2 = 0;
                if(!dfs(i, 1)) ok = 0;
                else{
                    ans += max(1, min(c1, c2));
                }
            }
                
        }
        if(ok) cout << ans;
        else cout << -1;
        puts("");


    }
}
