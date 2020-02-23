//16ms 8.3MB
class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> ans;
        int d1 = num + 1, d2 = num + 2;
        for(int i = 1; i <= sqrt(d1); ++i){
            if(d1 % i) continue;
            if(ans.size() == 0){
                ans.push_back(i);
                ans.push_back(d1/i);
            }
            else{
                int ab = abs(ans[0] - ans[1]), nd = abs(i - d1/i);
                if(nd < ab){
                    ans[0] = i;
                    ans[1] = d1/i;
                }
            }
        }
        for(int i = 1; i <= sqrt(d2); ++i){
            if(d2 % i) continue;
            int ab = abs(ans[0] - ans[1]), nd = abs(i - d2/i);
            if(nd < ab){
                ans[0] = i;
                ans[1] = d2/i;
            }
        }
        return ans;
    }
};
