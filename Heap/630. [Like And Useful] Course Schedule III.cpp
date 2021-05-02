// deadline first. and maintain a queue. so pop largest interval.
// maybe current. and this is the best. it is impossible that pop before is ans. 
// u can think about case if current interval is long.
// O(NlogN).

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        int day = 0;
        priority_queue<int> pq;
        for(auto &c: courses){
            int time = c[0], last = c[1];
            pq.push(time);
            day += time;
            while(day > last){
                day -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};
