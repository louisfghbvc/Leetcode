// Idea is monotonous increasing and binary search. O(NlogN + qlogq)

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        
        sort(rooms.begin(), rooms.end(), [](auto &a, auto &b){
            return a[1] > b[1];
        });
        
        for(int i = 0; i < queries.size(); ++i)
            queries[i].push_back(i);
        
        sort(queries.begin(), queries.end(), [](auto &a, auto &b){
            return a[1] > b[1];
        });
        
        vector<int> res(queries.size(), -1);
        int i = 0;
        
        set<int> st;
        for(auto &q: queries){
            int pj = q[0], sz = q[1], id = q[2];
            while(i < rooms.size() && rooms[i][1] >= sz){
                st.insert(rooms[i++][0]);
            }
            
            auto p = st.upper_bound(pj);
            if(p != st.end()){
                if(res[id] == -1)
                    res[id] = *p;
                else{
                    int od = abs(pj-res[id]);
                    int nd = abs(pj - *p);
                    if(od > nd){
                        res[id] = *p;
                    }
                    else if(od == nd){
                        res[id] = min(res[id], *p);
                    }
                }
            }
            if(p != st.begin()){
                if(res[id] == -1)
                    res[id] = *prev(p);
                else{
                    int od = abs(pj-res[id]);
                    int nd = abs(pj - *prev(p));
                    if(od > nd){
                        res[id] = *prev(p);
                    }
                    else if(od == nd){
                        res[id] = min(res[id], *prev(p));
                    }
                }
            }
        }
        
        return res;
    }
};
