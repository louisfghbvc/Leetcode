// go through y. and try to calculate the x range. get the sum.
// convert x to a another i
// O(N^2)

class Solution {
public:
    const int mod = 1e9+7;
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<int> x;
        for(auto &r: rectangles){
            x.push_back(r[0]);
            x.push_back(r[2]);
        }
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        
        // x mapping to i
        unordered_map<int, int> x2i; 
        for(int i = 0; i < x.size(); ++i) 
            x2i[x[i]] = i;
        
        // record used x
        vector<int> cnt(x.size()); 
        
        // line for y
        vector<vector<int>> L; 
        for(auto &r: rectangles){
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            // divide segment to two points
            L.push_back({y1, x1, x2, 1});
            L.push_back({y2, x1, x2, -1});
        }
        sort(L.begin(), L.end());
        
        long res = 0, cur_y = 0, cur_x_sum = 0;
        for(auto &l: L){
            int y = l[0], x1 = l[1], x2 = l[2], v = l[3];
            // calculate the area
            res = (res + (y - cur_y) * cur_x_sum) % mod; 
            
            cur_y = y;
            // use x, update
            for(int i = x2i[x1]; i < x2i[x2]; ++i)
                cnt[i] += v;
            
            cur_x_sum = 0;
            for(int i = 0; i+1 < x.size(); ++i){
                if(cnt[i]){
                    cur_x_sum += x[i+1] - x[i];
                }
            }
        }
        
        return res;
    }
};
