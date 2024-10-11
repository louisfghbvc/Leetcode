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


// Instead of split the array, just sort
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // goal: find the target friend that sit which one chair
        // idea:
        // maintain two set
        // one set for unoccupy, occupy => (leave t, idx)


        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<>> occupy;

        set<int> chair;
        for (int i = 0; i < times.size(); ++i)
            chair.insert(i);
        
        auto ans = times[targetFriend];
        sort(times.begin(), times.end());
        for (auto &t: times) {
            int arrive = t[0], leave = t[1];
            while (occupy.size() && occupy.top().first <= arrive) {
                chair.insert(occupy.top().second);
                occupy.pop();
            }
            if (t == ans) {
                return *chair.begin();
            }
            int id = *chair.begin(); chair.erase(chair.begin());
            occupy.push({leave, id});
        }

        return 0;
    }
};
