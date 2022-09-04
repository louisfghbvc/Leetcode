class Solution {
public:
    typedef pair<long, long> ii;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // goal: return the id of the room, held most meetings
        
        // idea: sort the meeting by start time 
        // go through the timestamp -> step by step TLE
        // go through the meetings -> all the meeting will occupy one room
        // simulate it
        
        sort(meetings.begin(), meetings.end());
        
        vector<int> cnt(n);
        
        priority_queue<ii, vector<ii>, greater<>> pq; // min-heap, {end_time, room_id}
        for (int i = 0; i < n; ++i)
            pq.push({0, i});
        
        priority_queue<ii, vector<ii>, greater<>> ok; // min-heap, {room_id, end_time}
        // TC: O(m*nlogn) SC: O(n)
        
        for (auto &m: meetings) {
            while (pq.size() && pq.top().first <= m[0]) {
                ok.push({pq.top().second, pq.top().first}); pq.pop();
            }
            if (ok.empty()) {
                ok.push({pq.top().second, pq.top().first}); pq.pop();
            }
             
            auto [i, end_time] = ok.top(); ok.pop();
            cnt[i]++;
            pq.push({max<long>(end_time, m[0]) + m[1] - m[0], i});
        }
        
        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};
