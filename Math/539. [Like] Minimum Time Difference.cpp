// O(1) calculate the timestamp

class Solution {
public:
    
    int conv(string &s){
        int h = 10 * (s[0]-'0') + (s[1]-'0');
        int m = 10 * (s[3]-'0') + (s[4]-'0');
        return h * 60 + m;
    }
    
    int findMinDifference(vector<string>& timePoints) {
        int cnt[24 * 60] = {};
        
        for(auto &s: timePoints){
            int time = conv(s);
            cnt[time]++;
            if(cnt[time] > 1) return 0;
        }
        
        int last = -1;
        int day = 24*60;
        int res = day;
        for(int i = 0; i < 2*day; ++i){
            if(cnt[i % day] == 0) continue;
            if(last != -1)
                res = min(i - last, res);
            last = i;
        }
        
        return res;
    }
};
