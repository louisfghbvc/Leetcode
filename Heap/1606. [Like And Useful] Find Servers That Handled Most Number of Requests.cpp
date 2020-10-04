// A schedule problem can always use priority_queue.
// note that tou need to understand what the problem says. and so that just done with that algorithm
// so use a ordered_set to maintain free server. just check now start time can poll how many server last end time
// add - as max to min. useful
// so just need to determine which can work. use lower_bound. if no server, just use begin, cuz smallest.
// why need lower_bound ? cuz the problem says should i+1, i+2..
// as u know the schedule problem, this is simple to done.
// O(KlogK + NlogN).

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = load.size();
        vector<int> fre(k);
        
        set<int> st; // can work
        for(int i = 0; i < k; ++i) st.insert(i);
        
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; ++i){
            int startT = arrival[i];
            int endT = arrival[i]+load[i];
            
            while(pq.size() && -pq.top().first <= startT){
                int server = pq.top().second; pq.pop();
                st.insert(server);
            }
            
            if(st.size()){
                auto p = st.lower_bound(i%k);
                if(p == st.end()) p = st.begin();
                fre[*p]++;
                pq.push({-endT, *p});
                st.erase(*p);
            }
        }
        
        int mx = *max_element(fre.begin(), fre.end());
        vector<int> res;
        for(int i = 0; i < k; ++i) if(fre[i] == mx) res.push_back(i);
        
        return res;
    }
};
