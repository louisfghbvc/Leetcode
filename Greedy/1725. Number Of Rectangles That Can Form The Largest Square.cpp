// Simple O(N).

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rect) {
        vector<int> arr;
        for(auto&x: rect){
            arr.push_back(min(x[0], x[1]));
        }
        int mx = *max_element(arr.begin(), arr.end());
        int c = 0;
        for(int x: arr){
            c += x == mx;
        }
        return c;
    }
};
