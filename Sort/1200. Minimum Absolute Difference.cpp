// O(NlogN). sorting and record minimum.

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> res;
        int mn = 1e9;
        for(int i = 1; i < arr.size(); ++i){
            if(arr[i] - arr[i-1] < mn){
                mn = arr[i] - arr[i-1];
                res = {{arr[i-1], arr[i]}};
            }
            else if(arr[i] - arr[i-1] == mn)
                res.push_back({arr[i-1], arr[i]});
        }
        
        return res;
    }
};
