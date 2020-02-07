class Solution {
public:
    const int h[10] = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
    vector<int> ans;
    void dfs(int id, int d, int &dep, int s){
        if(id > 10) return;
        if(d == dep){
            ans.push_back(s);
            return;
        }
        for(int i = id; i < 10; ++i){
            dfs(i + 1, d + 1, dep, s|(1<<i));
        }
    }
    vector<string> readBinaryWatch(int num) {
        if(!num)
            return {"0:00"};
        dfs(0, 0, num, 0);
        vector<string> res;
        for(auto a : ans){
            int hs = 0, ms = 0;
            for(int i = 0; i < 4; ++i){
                if(a & (1 << i))
                    hs += h[i];
            }
            if(hs >= 12) continue;
            for(int i = 4; i < 10; ++i){
                if(a & (1 << i))
                    ms += h[i];
            }
            if(ms >= 60) continue;
            string tmp = "";
            tmp += to_string(hs);
            tmp += ":";
            if(ms < 10)
                tmp += "0";
            tmp += to_string(ms);
            res.push_back(tmp);
        }
        return res;
    }
};
