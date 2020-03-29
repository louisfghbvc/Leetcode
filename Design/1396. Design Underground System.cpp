class UndergroundSystem {
private:
    double eps = 1e-5;
    map<pair<string, string>, pair<int, int>> mp;
    unordered_map<int, pair<string, int>> idi;
public:
    UndergroundSystem() {
        mp.clear();
        idi.clear();
    }
    
    void checkIn(int id, string sN, int t) {
        idi[id] = {sN, t};
    }
    
    void checkOut(int id, string sN, int t) {
        auto tmp = idi[id];
        mp[{tmp.first, sN}].first += (t - tmp.second);a
        mp[{tmp.first, sN}].second++; 
    }
    
    double getAverageTime(string sS, string eS) {
        auto t = mp[{sS, eS}];
        return (double)t.first / t.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
