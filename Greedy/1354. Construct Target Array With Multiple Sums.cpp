// O(NlogN). pop largest. and use mod. since it multiple of big.

class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        long sum = 0;
        priority_queue<int> pq;
        for(int x: target){
            sum += x;
            pq.push(x);
        }
        while(1){
            int m = pq.top(); pq.pop();
            sum -= m;
            if(m == 1 || sum == 1) return true;
            if(m < sum || sum == 0 || m % sum == 0) return false;
            m %= sum;
            sum += m;
            pq.push(m);
        }
        return true;
    }
};
