// Binary search and greedy
// O(logN*NlogN)

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.rbegin(), workers.rend());
        
        auto good = [&](int k){
            if(workers.size() < k) return false;
            
            multiset<int> st(workers.begin(), workers.begin() + k);
            int remain = pills;
            
            for(int i = k-1; i >= 0; --i){
                auto it = st.lower_bound(tasks[i]);
                
                if(it == st.end()){
                    if(!remain) return false;
                    remain--;
                    it = st.lower_bound(tasks[i] - strength);
                    if(it == st.end()) return false;
                }
                
                st.erase(it);
            }
            
            return true;
        };
        
        int l = 1, r = n;
        int res = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(good(mid)) res = mid, l = mid+1;
            else r = mid-1;
        }
        return res;
    }
};
