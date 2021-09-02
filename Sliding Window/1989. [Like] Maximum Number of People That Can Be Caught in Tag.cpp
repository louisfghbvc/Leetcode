// push `it` to queue.
// pop out all out range. and pop one is closest. since each cost is same, so just pop
// O(N)
class Solution {
public:
    int catchMaximumAmountofPeople(vector<int>& team, int dist) {
        queue<int> q;
        for(int i = 0; i < team.size(); ++i){
            if(team[i]) 
                q.push(i);
        }
        
        int res = 0;
        for(int i = 0; i < team.size(); ++i){
            if(team[i]) continue;
            while(q.size() && i - q.front() > dist) q.pop();
            if(q.size() && abs(i - q.front()) <= dist){
                res++;
                q.pop();
            }
        }
        
        return res;
    }
};

// Two Pointers T:O(N) S:O(1). tricky
