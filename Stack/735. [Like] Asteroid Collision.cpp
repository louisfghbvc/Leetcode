// Simulate.
// O(N). Space O(N). just simple maintain use two array.
// Autually, can use one N space.
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        vector<int> pos;
        for(int x: asteroids){
            if(x > 0)
                pos.push_back(x);
            else{
                if(pos.size()){
                    bool gg = 0;
                    while(pos.size() && !gg){
                        if(pos.back() == abs(x)) pos.pop_back(), gg = 1;
                        else if(pos.back() < abs(x)) pos.pop_back();
                        else gg = 1;
                    }
                    if(!gg) res.push_back(x);
                }
                else{
                    res.push_back(x);
                }
            }
        }
        if(pos.size()) res.insert(res.end(), pos.begin(), pos.end());
        return res;
    }
};
