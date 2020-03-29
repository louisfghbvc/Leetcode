class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                for(int k = j + 1; k < n; ++k){
                    if(rating[i] < rating[j] && rating[j] < rating[k])
                        ans++;
                    else if(rating[i] > rating[j] && rating[j] > rating[k])
                        ans++;
                }
            }
        }
        return ans;
    }
};
