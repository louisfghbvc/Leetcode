class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int> > pq;
        sort(events.begin(), events.end());
        int i = 0, n = events.size(), cnt = 0;
        for(int d = 1; d <= 100000; ++d){
            while(i < n && events[i][0] == d){
                pq.push(events[i++][1]);
            }
            while(pq.size() && pq.top() < d){
                pq.pop();
            }
            if(pq.size()){
                pq.pop();
                cnt++;
            }
        }
        return cnt;
    }
};
