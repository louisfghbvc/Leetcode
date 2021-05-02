// Sort, and maintain the interval.
// O(NlogN)

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& I, vector<int>& ordQ) {
        vector<int> res(ordQ.size(), -1);
        
        vector<vector<int>> Q;
        for(int i = 0; i < ordQ.size(); ++i){
            Q.push_back({ordQ[i], i});
        }
        sort(Q.begin(), Q.end());
        sort(I.begin(), I.end());
        
        set<pair<int, int>> st; // inteval, right
        int i = 0;
        for(auto &q: Q){
            int id = q[1], in = q[0];
            while(i < I.size() && I[i][0] <= in){
                st.insert({I[i][1] - I[i][0] + 1, I[i][1]});
                i++;
            }
            while(st.size() && st.begin()->second < in){
                st.erase(st.begin());
            }
            if(st.size())
                res[id] = st.begin()->first; 
        }
        return res;
    }
};

// use minheap.
class Solution {
public:
    typedef pair<int, int> ii;
    vector<int> minInterval(vector<vector<int>>& I, vector<int>& ordQ) {
        vector<int> res(ordQ.size(), -1);
        
        vector<vector<int>> Q;
        for(int i = 0; i < ordQ.size(); ++i){
            Q.push_back({ordQ[i], i});
        }
        sort(Q.begin(), Q.end());
        sort(I.begin(), I.end());
        
        priority_queue<ii, vector<ii>, greater<ii>> pq; // interval, right
        int i = 0;
        for(auto &q: Q){
            int id = q[1], in = q[0];
            while(i < I.size() && I[i][0] <= in){
                pq.push({I[i][1] - I[i][0] + 1, I[i][1]});
                i++;
            }
            while(pq.size() && pq.top().second < in){
                pq.pop();
            }
            if(pq.size())
                res[id] = pq.top().first; 
        }
        return res;
    }
};
