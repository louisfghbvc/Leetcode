// Array tour.
// use accumulate sum, when out range. substract that value.
// O(N)

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n);
        vector<int> tour(n+2);
        for(auto &v: bookings){
            tour[v[0]] += v[2];
            tour[v[1]+1] -= v[2];
        }
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            sum += tour[i];
            res[i-1] = sum;
        }
        return res;
    }
};
