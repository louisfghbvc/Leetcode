// O(N)
// Just Greedy.
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(), candies.end());
        vector<bool> ok(candies.size());
        for(int i = 0; i < candies.size(); ++i){
            if(candies[i] + extraCandies >= mx) ok[i] = 1;
                
        }
            
        return ok;
    }
};
