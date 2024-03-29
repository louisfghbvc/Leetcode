// LIS tweak.
// O(NlogN).
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> res;
        vector<int> arr;
        for(int x: obstacles){
            if(arr.empty() || x >= arr.back()){
                arr.push_back(x);
                res.push_back(arr.size());
            }
            else{
                auto p = upper_bound(arr.begin(), arr.end(), x);
                *p = x;
                res.push_back((p - arr.begin()) + 1);
            }
            
        }
        return res;
    }
};
