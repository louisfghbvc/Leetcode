//4ms 8.3MB
class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> ans;
        int d1 = num + 1, d2 = num + 2, d;
        for(int i = sqrt(d1); i >= 1; --i){
            if(d1 % i) continue;
            ans = {i, d1/i};
            d = abs(i - d1/i);
            break;
            
        }
        for(int i = sqrt(d2); i >= 1; --i){
            if(d2 % i) continue;
            if(d > abs(i - d2/i)){
                ans = {i, d2/i};
                break;
            }
        }
        return ans;
    }
};
