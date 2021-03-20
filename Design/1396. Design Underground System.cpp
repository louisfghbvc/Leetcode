// Use two map. avg O(1).

class UndergroundSystem {
public:
    
    unordered_map<string, unordered_map<string, pair<int, int>>> mp;
    unordered_map<int, pair<string, int>> user;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        user[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto &pre = user[id];
        auto &cur = mp[pre.first][stationName];
        cur.first += t - pre.second;
        cur.second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto &cur = mp[startStation][endStation];
        return (double)cur.first / cur.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
