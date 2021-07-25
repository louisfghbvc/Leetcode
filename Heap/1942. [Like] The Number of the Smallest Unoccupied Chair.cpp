// Use set or heap, and use a map to mapping id.

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        set<int> chair;
        for(int k = 0; k < n; ++k) chair.insert(k);
            
        int i = 0;
        vector<vector<int>> arr;
        for(auto &val: times){
            arr.push_back({val[0], 1, i});
            arr.push_back({val[1], -1, i});
            i++;
        }
        sort(arr.begin(), arr.end());
        
        map<int, int> seat; // user, chair index
        int t = 0;
        for(auto &val: arr){
            int id = val[2];
            if(val[1] < 0){ // leave
                chair.insert(seat[id]); 
            }
            else{ // enter
                int x = *chair.begin();
                seat[id] = x;
                if(id == targetFriend) return x;
                chair.erase(chair.begin());
            }
        }
        
        return -1;
    }
};
