// O(N). Equal char no need to move.
// only consider xx yy. means pattern is same. only move 1. greedy this pattern.
// only x y impossible.

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        // xx yy -> 1
        // xy yx -> 2
        
        int n = s1.size();
        set<pair<char, char>> st;
        int cost = 0;
        for(int i = 0; i < n; ++i){
            if(s1[i] != s2[i]){
                if(st.count({s1[i], s2[i]})){
                    st.erase({s1[i], s2[i]});
                    cost++;
                }
                else st.insert({s1[i], s2[i]});
            }
        }
        
        if(st.size() == 1) return -1;
        return cost + st.size();
    }
};

// Optimal
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        // xx yy -> 1
        // xy yx -> 2
        
        int n = s1.size();
        bool xy = 0, yx = 0;
        int cost = 0;
        for(int i = 0; i < n; ++i){
            if(s1[i] != s2[i]){
                if(s1[i] == 'x' && s2[i] == 'y'){
                    if(xy) cost++;
                    xy ^= 1;
                }
                else{
                    if(yx) cost++;
                    yx ^= 1;
                }
            }
        }
        
        if(xy ^ yx) return -1;
        return cost + xy + yx;
    }
};
