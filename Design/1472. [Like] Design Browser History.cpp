// two array to keep history, and some map, not optimal Simulate
// slow method.

class BrowserHistory {
public:
    unordered_map<string, int> mp;
    unordered_map<int, string> i2s;
    int f[5005];
    int b[5005];
    int cur;
    BrowserHistory(string homepage) {
        memset(f, -1, sizeof f);
        memset(b, -1, sizeof b);
        mp[homepage] = mp.size();
        cur = 0;
        i2s[cur] = homepage;
    }
    
    void visit(string url) {
        if(!mp.count(url)){
            mp[url] = mp.size();
            i2s[mp[url]] = url;
        }
        f[cur] = mp[url];
        b[mp[url]] = cur;
        cur = mp[url];
    }
    
    string back(int steps) {
        // printf("back %d\n", steps);
        for(int i = 0; i < steps; ++i){
            int v = b[cur];
            if(v == -1) break;
            cur = v;
            // cout << i2s[cur] << endl;
        }
        return i2s[cur];
    }
    
    string forward(int steps) {
        // printf("forward %d\n", steps);
        for(int i = 0; i < steps; ++i){
            int v = f[cur];
            if(v == -1) break;
            cur = v;
            // cout << i2s[cur] << endl;
        }
        return i2s[cur];
    }
};

// More Optimal, use two stack.
class BrowserHistory {
public:
    string cur;
    stack<string> b, f;
    BrowserHistory(string homepage) {
        cur = homepage;
    }
    
    void visit(string url) {
        f = stack<string>();
        b.push(cur);
        cur = url;
    }
    
    string back(int steps) {
        while(steps > 0 && !b.empty()){
            f.push(cur);
            cur = b.top();
            b.pop();
            steps--;
        }
        return cur;
    }
    
    string forward(int steps) {
        while(steps > 0 && !f.empty()){
            b.push(cur);
            cur = f.top();
            f.pop();
            steps--;
        }
        return cur;
    }
};

// Best Optimal use List or Array. 666
// use t maintain size. because history is continuous
// O(1)
// Like Sliding window.
class BrowserHistory {
public:
    string st[5005];
    int p, t;
    BrowserHistory(string homepage) {
        st[p = 0] = homepage;
    }
    
    void visit(string url) {
        st[t = ++p] = url;
    }
    
    string back(int steps) {
        return st[p = max(0, p-steps)];
    }
    
    string forward(int steps) {
        return st[p = min(t, p+steps)];
    }
};
