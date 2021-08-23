// Sort by start time, and heap is deadline first. O(NlogN).
// Record maximum size
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort by start time
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<>> pq;
        int mx = 0;
        for(auto &i: intervals){
            while(pq.size() && pq.top() <= i[0]) pq.pop();
            pq.push(i[1]);
            mx = max(mx, (int)pq.size());
        }
        return mx;
    }
};

// Line sweep, Record maximum size of go through
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for(auto &i: intervals){
            mp[i[0]]++;
            mp[i[1]]--;
        }
        // traveral all x
        int mx = 0, sum = 0;
        for(auto &[_, v]: mp){
            sum += v;
            mx = max(sum, mx);
        }
        return mx;
    }
};
