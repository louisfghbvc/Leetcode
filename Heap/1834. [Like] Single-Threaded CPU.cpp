// O(NlogN).

class Solution {
public:
    typedef pair<int, int> ii;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        vector<vector<int>> arr;
        for(int i = 0; i < tasks.size(); ++i)
            arr.push_back({tasks[i][0], tasks[i][1], i});
        
        sort(arr.begin(), arr.end(), [&](auto &a, auto &b){
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]) || (a[0] == b[0] && a[1] == b[1] && a[2] < b[2]);
        });
            
        int i = 0, n = tasks.size();
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        
        vector<int> res;
        long t = 0;
        while(i < n || pq.size()){
            if(pq.empty()){
                t = arr[i][0];
                pq.push({arr[i][1], arr[i][2]});
                i++;
            }
            else{
                auto [p, id] = pq.top(); pq.pop();
                res.push_back(id);
                t += p;
                while(i < n && arr[i][0] <= t){
                    pq.push({arr[i][1], arr[i][2]});
                    i++;
                }
            }
        }
        return res;
    }
};
