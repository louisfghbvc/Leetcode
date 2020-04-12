//0ms 6.2MB
//PQ
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(const auto &x: stones)
            pq.push(x);
        while(pq.size() > 1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if(a > b) pq.push(a-b);
        }
        return pq.size()==0 ? 0: pq.top();
    }
};
