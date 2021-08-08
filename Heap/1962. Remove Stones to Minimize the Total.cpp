// Just priority_queue. O(KlogN + NlogN).

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int x: piles) pq.push(x);
        while(k--){
            int v = pq.top(); pq.pop();
            v = v - v/2;
            pq.push(v);
        }
        int res = 0;
        while(pq.size()){
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
