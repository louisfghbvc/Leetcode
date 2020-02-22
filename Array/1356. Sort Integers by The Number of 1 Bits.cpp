//20ms 9.4MB
class Solution {
public:
    static bool com(const int &a, const int &b){
        if(__builtin_popcount(a) == __builtin_popcount(b))
            return a < b;
        return __builtin_popcount(a) < __builtin_popcount(b);
    } 
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), com);
        return arr;
    }
};
