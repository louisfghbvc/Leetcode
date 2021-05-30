// do as problem says. if can not put, pop out the inq.
// O(NlogN).

class Solution {
public:
    typedef pair<int, int> ii;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> res;
        
        priority_queue<ii, vector<ii>, greater<ii>> pq; // can do
        for(int i = 0; i < n; ++i) pq.push({servers[i], i});
        
        priority_queue<ii, vector<ii>, greater<ii>> inq; // time, i
        
        int t = 0, j = 0;
        while(true){
            if(j == m) break;
            
            while(inq.size() && inq.top().first <= t){
                pq.push({servers[inq.top().second], inq.top().second});
                inq.pop();
            }
            
            bool f = 0;
            for(; j < m && j <= t; ++j){
                if(pq.size()){
                    // cout << "sec " << t << " cur " << j << " into " << pq.top().second << "\n";
                    // cout << "leave " << t + tasks[j] << "\n";
                    inq.push({t + tasks[j], pq.top().second});
                    res.push_back(pq.top().second);
                    pq.pop();
                }
                else{
                    f = 1;
                    break;
                }
            }
            if(f){
                t = inq.top().first;
                pq.push({servers[inq.top().second], inq.top().second});
                inq.pop();
            } 
            else t++;
        }
        
        return res;
    }
};
