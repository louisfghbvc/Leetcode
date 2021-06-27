class MovieRentingSystem {
public:
    int N;
    
    unordered_map<int, set<pair<int, int>>> unR; // unrent movie, set: price, shop
    unordered_map<int, set<pair<int, int>>> R; // rent movie, set: price, shop
    set<vector<int>> cheapestP; // set: price, shop, movie
    map<pair<int, int>, int> wPrice; // shop,movie -> price
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        N = n;
        for(auto &e: entries){
            unR[e[1]].insert({e[2], e[0]});
            wPrice[{e[0], e[1]}] = e[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        
        auto& st = unR[movie];
        auto it = st.begin(); 
        for(int i = 0; i < 5 && it != st.end(); ++i, ++it){
            res.push_back(it->second);
        }
        
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = wPrice[{shop, movie}]; 
        
        unR[movie].erase({price, shop});
        R[movie].insert({price, shop});
        
        cheapestP.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = wPrice[{shop, movie}]; 
        
        R[movie].erase({price, shop});
        unR[movie].insert({price, shop});
        
        cheapestP.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        
        auto it = cheapestP.begin(); 
        for(int i = 0; i < 5 && it != cheapestP.end(); ++i, ++it){
            res.push_back({(*it)[1], (*it)[2]});
        }
        
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
