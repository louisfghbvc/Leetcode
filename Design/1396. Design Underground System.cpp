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

// Concate string.
class UndergroundSystem {
public:
    
    unordered_map<string, pair<int, int>> mp;
    unordered_map<int, pair<string, int>> user;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        user[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto &pre = user[id];
        string route = pre.first + ">" + stationName;
        auto &cur = mp[route];
        cur.first += t - pre.second;
        cur.second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + ">" + endStation;
        auto &cur = mp[route];
        return (double)cur.first / cur.second;
    }
};

