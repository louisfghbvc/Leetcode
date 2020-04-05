//0ms 6.6MB. O(N^2) can pass. 
//optimal prefix > 0. sum += prefix. same as max(tmp += small * time, sum);
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int ans = 0, total = 0;
        for(int i = satisfaction.size() - 1; i >= 0; --i){
            if(total + satisfaction[i] > 0){
                total += satisfaction[i];
                ans += total;
            }
        }
        return ans;
    }
};
