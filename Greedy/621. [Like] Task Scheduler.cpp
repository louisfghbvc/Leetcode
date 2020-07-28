// Greedy O(N). So maintain a queue size n.
// use set to sort from big to small.
// so grab the fre largest if not in queue
// simulate. foreach char if not in queue.
// that char is candicate otherwise use 26 as idle.
// May not be Optimal but think by myself.

class Solution {
public:
    typedef pair<int, int> ii;
    #define x first
    #define y second
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();
        int fre[30] = {};
        for(auto &c: tasks) fre[c - 'A']++;
        set<ii> st;
        for(int i = 0; i < 26; ++i) if(fre[i]){
            st.insert({fre[i], i});
        }
        int res = 0;
        memset(fre, 0, sizeof fre);
        deque<int> dq;
        while(st.size()){
            int c = 26;
            for(auto i = st.rbegin(); i != st.rend(); ++i){
                if(!fre[(*i).y]){
                    c = (*i).y;
                    auto tt = *i;
                    st.erase(tt);
                    if(--tt.x) st.insert(tt);
                    break;
                }
            }
            dq.push_back(c);
            fre[c]++;
            res++;
            if(dq.size() > n){
                fre[dq.front()]--; dq.pop_front();
            }
        }
        return res;
    }
};
