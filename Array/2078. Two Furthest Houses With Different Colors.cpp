
// just check begin, end. O(N)

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int res = 0;
        int n = colors.size();
        for(int i = 0; i < n; ++i){
            if(colors[i] != colors[0]) res = max(res, i);
            if(colors[i] != colors.back()) res = max(res, n-i-1);
        }
        return res;
    }
};
