class FoodRatings {
public:
    
    unordered_map<string, set<pair<int, string>>> mp; // cuisine -> {rate, name}
    unordered_map<string, string> mptype; // food -> type
    unordered_map<string, int> rate; // food -> rating
    
    // name: distinct
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            mp[cuisines[i]].insert({-ratings[i], foods[i]});
            mptype[foods[i]] = cuisines[i];
            rate[foods[i]] = -ratings[i];
        }
        
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = mptype[food];
        int &oldRating = rate[food];
        mp[cuisine].erase({oldRating, food});
        mp[cuisine].insert({-newRating, food});
        oldRating = -newRating;
    }
    
    string highestRated(string cuisine) {
        return mp[cuisine].begin()->second;    
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
