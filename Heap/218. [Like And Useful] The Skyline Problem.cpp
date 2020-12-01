// Line sweep algorithm use multiset is really easy to code.
// O(NlogN). first down segment to (left point, height) + (right point, height).
// sort by left then height. and just go through left to right. grab biggest height. when end point pop heap.
// strategy use negative as begin, positive as end point. 

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;        
        int n = buildings.size();
        
        vector<vector<int>> arr;
        for(auto &h: buildings){
            arr.push_back({h[0], -h[2]});
            arr.push_back({h[1], h[2]});
        }
        sort(arr.begin(), arr.end());
        
        int prev_y = 0, cur_y;
        multiset<int> st = {0};
        for(auto &h: arr){
            if(h[1] < 0) st.insert(-h[1]);
            else st.erase(st.find(h[1]));
            
            cur_y = *st.rbegin();
            if(prev_y != cur_y){
                res.push_back({h[0], cur_y});
                prev_y = cur_y;
            }
        }
        
        return res;
    }
};

// priority_queue, super fast. so just look as segment. and just loop it. check cur end point.
// if is still small then heap endtime. then just push push push.
// and same time. cur_y will be heap top height. when not duplicate with res back, push it.
// So, how to pop heap? well... if endtime is smaller than current time. pop out.
// and same time. check cur_y is same or not.
// just go through testcase. it will be very clean and awesome.
// O(NlogN). this method is more strategy. 

class Solution {
public:
    #define ht first 
    #define ed second
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;        
        int n = buildings.size();

        priority_queue<pair<int, int>> pq;
        int i = 0, cur_x, cur_y;
        while(i < n || pq.size()){
            if(pq.empty() || i < n && buildings[i][0] <= pq.top().ed){
                cur_x = buildings[i][0];
                while(i < n && buildings[i][0] == cur_x){
                    pq.push({buildings[i][2], buildings[i][1]});
                    i++;
                }
            }
            else{
                cur_x = pq.top().ed;
                while (pq.size() && pq.top().ed <= cur_x)
                    pq.pop();
            }
            
            cur_y = pq.empty() ? 0 : pq.top().ht;
            if(res.empty() || res.back()[1] != cur_y){
                res.push_back({cur_x, cur_y});
            }
        }
        
        return res;
    }
};
