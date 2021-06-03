// Heap, Greedy. 3 case. O(NlogN). Gernal.
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        typedef pair<int, int> ii;
        
        // last, length
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        
        for(int x: nums){
            if(pq.empty() || pq.top().first == x){ // add one
                pq.push({x, 1});
            }
            else{
                while(pq.size() && pq.top().first+1 != x){ // pop it will not equal
                    auto [i, len] = pq.top(); pq.pop();
                    if(len < 3) return false;
                }
                if(pq.size()){
                    auto [i, len] = pq.top(); pq.pop();
                    pq.push({x, len+1});
                }
                else{
                    pq.push({x, 1});
                }
            }
            
        }
        
        while(pq.size()){
            auto [i, len] = pq.top(); pq.pop();
            if(len < 3) return false;
        }
        
        return true;
    }
};


// Greedy add prev one, or extand 3.
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> left, end;
        for(int x: nums) left[x]++;
        for(int x: nums){
            if(!left[x]) continue;
            left[x]--;
            if(end[x-1]){ // try to add one
                end[x-1]--;
                end[x]++;
            }
            else if(left[x+1] && left[x+2]){ // or just grab 2.
                left[x+1]--;
                left[x+2]--;
                end[x+2]++;
            }
            else return false;
        }
        return true;
    }
};
