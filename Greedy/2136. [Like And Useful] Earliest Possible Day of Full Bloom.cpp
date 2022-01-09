// observe that the order is base one two choice

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<vector<int>> arr;
        for(int i = 0; i < plantTime.size(); ++i)
            arr.push_back({plantTime[i], growTime[i]});
        
        sort(arr.begin(), arr.end(), [&](auto &a, auto &b){
            int mxa = max(a[0]+a[1], a[0]+b[0]+b[1]);
            int mxb = max(b[0]+b[1], b[0]+a[0]+a[1]);
            return mxa < mxb;
        });
        
        int res = 0;
        int time = 0;
        for(int i = 0; i < arr.size(); ++i){
            res = max(res, time + arr[i][0] + arr[i][1]);
            time += arr[i][0];
        }
        
        return res;
    }
};
