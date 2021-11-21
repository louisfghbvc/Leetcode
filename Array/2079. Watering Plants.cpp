// simple for loop,
// when not enough try to update capacity
// O(N)

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int res = 0;
        int cur = capacity;
        for(int i = 0; i < plants.size(); ++i){
            if(cur < plants[i]) res += 2*i, cur = capacity;
            cur -= plants[i];
            res++;
        }
        
        return res;
    }
};
