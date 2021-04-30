// O(log(bound) * log(bound)) .
// Just Enum them


class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res;
        
        // enum i, enum j
        for(int powX = 1; powX <= bound; powX *= x){
            for(int powY = 1; powX + powY <= bound; powY *= y){
                res.push_back(powX + powY);
                if(powY * y == 1) break;
            }
            if(powX * x == 1) break;
        }
        
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        
        return res;
    }
};
