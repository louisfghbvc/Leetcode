// use set to maintain heap.
// so observe that. odd can*2 once. so odd we just*2. so that odd never *2 again.
// only down biggest.
// and when biggest is even. can down to biggest/2.
// O(NlogNlogK). use tree.

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> st;
        for(int x: nums){
            st.insert(x % 2 ? x*2 : x);
        }
        int res = *st.rbegin() - *st.begin();
        while(*st.rbegin() % 2 == 0){
            st.insert(*st.rbegin() / 2);
            st.erase(*st.rbegin());
            res = min(res, *st.rbegin() - *st.begin());
        }
        return res;
    }
};


// More fast, just use maxheap. Record minimum
// O(NlogN).
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn = INT_MAX;
        for(int x: nums){
            int px = x%2 ? x*2 : x;
            pq.push(px);
            mn = min(px, mn);
        }
        int res = pq.top() - mn;
        while(pq.top() % 2 == 0){
            int big = pq.top(); pq.pop();
            mn = min(big/2, mn);
            pq.push(big/2);
            res = min(res, pq.top()-mn);
        }
        return res;
    }
};
