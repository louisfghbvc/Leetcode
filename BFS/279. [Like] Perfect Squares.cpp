// BFS + prune
class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        queue<int> q;
        unordered_set<int> st;
        for(int i = 1; i*i <= n; ++i){
            v.push_back(i*i);
            q.push(i*i);
            st.insert(i*i);
        } 
        int dep = 1;
        while(!q.empty()){
            // cout << q.size() << endl;
            for(int s = q.size()-1; s >= 0; --s){
                int cur = q.front(); q.pop();  
                // cout << dep << " " << cur << endl;
                if(cur == n) return dep;
                for(int i = 0; i < v.size(); ++i){
                    if(cur + v[i] > n) break;
                    if(st.count(cur+v[i])) continue;
                    st.insert(cur+v[i]);
                    q.push(cur+v[i]);
                }
            }
            dep++;
        }
        return n;
    }
};

// Dp
