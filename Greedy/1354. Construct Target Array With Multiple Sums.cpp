class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq(begin(target), end(target));
        long sum = 0;
        for(auto x: target)
            sum += x;
        int n = target.size(), t;
        while(1){
            t = pq.top(); pq.pop();
            if(t == 1) return true;
            sum -= t;
            if(t <= sum) return false;
            t %= sum;
            sum += t;
            pq.push(t);
        }
    }
};
/** recursive method
class Solution {
public:
    bool isPossible(vector<int>& target) {
        int mx = 0, id = 0;
        for(int i = 0; i < target.size(); ++i){
            if(mx < target[i]){
                mx = target[i];
                id = i;
            }
        }
        if(mx == 1) return true;
        for(int i = 0; i < target.size(); ++i){
            if(i == id) continue;
            if(target[i] > mx) return false;
            mx -= target[i];
        }
        target[id] = mx;
        return isPossible(target);
    }
};




**/
