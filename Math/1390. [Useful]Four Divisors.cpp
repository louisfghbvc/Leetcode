//936~1716ms 9.9MB
class Solution {
public:
    
    int sumFourDivisors(vector<int>& nums) {
        const int N = 100005;
        bool np[N] = {false};
        vector<int> pr;
        for(int i = 2; i < N; ++i){
            if(!np[i]){
                pr.push_back(i);
                for(int j = 2*i; j < N; j+=i){
                    np[j] = true;
                }
            }
        }
        int ans = 0;
        for(auto x: nums){
            int t = x;
            int d = 1, cnt, d2 = 1;
            for(int i = 0; i < pr.size(); ++i){
                if(pr[i] > x) break;
                cnt = 0;
                while(x % pr[i] == 0){
                    x /= pr[i];
                    cnt++;
                }
                int tmp = 0;
                for(int k = 0; k < cnt + 1; ++k)
                    tmp += pow(pr[i], k); 
                d2 *= tmp;
                d *= (cnt+1);
            }
            if(d == 4) ans += d2;

            
        }
        return ans;
    }
};
