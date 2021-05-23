// O(NlogN). Straight forward. use treeset.

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        int far = 0;
        
        set<int> ind;
        for(int i = 0; i < n; ++i){
            if(s[i] == '0') ind.insert(i);
        }
        
        queue<int> q;
        q.push(0);
        while(q.size()){
            int i = q.front(); q.pop();
            if(i == n-1) return true;
            
            auto p = ind.lower_bound(i + minJump);
            while(p != ind.end()){
                if((*p) - i > maxJump) break;
                q.push(*p);
                auto d = p;
                p = next(p);
                ind.erase(d);
            }
            
        }
        
        return false;
    }
};

// Array tour, Line sweep. O(N). Dp
// Sliding window.

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        
        vector<bool> dp(n);
        dp[0] = 1;
        
        int pre = 0;
        for(int i = 1; i < n; ++i){
            if(i - minJump >= 0)
                pre += dp[i - minJump];
            if(i - maxJump - 1 >= 0)
                pre -= dp[i - maxJump - 1];
            dp[i] = s[i] == '0' && pre > 0;
        }
        
        return dp[n-1];
    }
};
