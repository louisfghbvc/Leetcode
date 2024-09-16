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


// Sort

class Solution {
public:
    int conv(string& s) {
        int h = (s[0]-'0')*10 + (s[1]-'0');
        int m = (s[3]-'0')*10 + (s[4]-'0');
        return h * 60 + m;
    }

    int findMinDifference(vector<string>& timePoints) {
        // goal: find the minimum diff in two list

        // e.g
        // ["23:59", "00:00"] => dif = 1
        // means => 0 = 24:00

        // idea:
        // we convert time to minutes
        // we sort time points, add padding 24:00

        // ["23:59", "00:00"] => [0:00, 23:59, 24:00]

        vector<int> arr;
        for (auto &s: timePoints)
            arr.push_back(conv(s));

        ranges::sort(arr);

        int n = arr.size();
        arr.resize(2*n);
        for (int i = 0; i < n; ++i)
            arr[n+i] = arr[i] + 24*60;

        int ans = 1e9;
        for (int i = 1; i < 2*n; ++i)
            ans = min(ans, arr[i] - arr[i-1]);

        return ans;
    }
};
