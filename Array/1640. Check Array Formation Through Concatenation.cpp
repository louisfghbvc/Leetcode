// BF. O(N^2).
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = pieces.size();
        int i = 0;
        for(; i < arr.size(); ){
            bool f = 0;
            for(int j = 0; j < n; ++j){
                int k = 0;
                if(arr[i] == pieces[j][k]){
                    f = 1;
                    while(k < pieces[j].size() && arr[i] == pieces[j][k]) i++, k++;
                    if(k != pieces[j].size()) return 0;
                    break;
                }
            }
            if(!f) return 0;
        }
        return i == arr.size();
    }
};
