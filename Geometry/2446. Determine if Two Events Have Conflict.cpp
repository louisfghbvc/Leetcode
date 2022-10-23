class Solution {
public:
    
    // convert to minute
    int conv(string &s) {
        return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
    }
    
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        // idea: convert event -> {start, end}
        
        pair<int, int> e1 = {conv(event1[0]), conv(event1[1])};
        pair<int, int> e2 = {conv(event2[0]), conv(event2[1])};
        
        if (e1.first > e2.first) swap(e1, e2);
        
        return e1.second >= e2.first;
    }
};
