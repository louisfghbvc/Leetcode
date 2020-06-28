// Straight Forward. O(NLogN)
// Use set to check.

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        set<pair<int, int>> st;
        st.insert({x,y});
        for(auto &c: path){
            if(c == 'N'){
                y++;
            }
            else if(c == 'S'){
                y--;
            }
            else if(c == 'E'){
                x++;
            }
            else{
                x--;
            }
            if(st.count({x, y})) return true;
            st.insert({x, y});
        }
        return false;
    }
};
