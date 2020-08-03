// O(Nlog(N)). Simple
class Solution {
public:
    int RR(int d){
        if(d == 0) return 0;
        if(d == 1) return 1;
        if(d == 2) return 5;
        if(d == 5) return 2;
        if(d == 6) return 9;
        if(d == 8) return 8;
        if(d == 9) return 6;
        return -1;
    }
    bool vv(int x){
        bool ok = false;
        while(x > 0){
            int tt = RR(x%10);
            if(tt == -1) return false;
            if(tt == 2 || tt == 5 || tt == 6 || tt == 9) ok = true;
            x /= 10;
        }
        return ok;
    }
    int rotatedDigits(int N) {
        int cnt = 0;
        for(int i = 1; i <= N; ++i){
            if(vv(i)) cnt++;
        }
        return cnt;
    }
};

// O(N). dp. 10 is divide 1 and 0
// 100 divide 10 0, 1000 => 100 0
// 1 is vaild but not good. 2 is good
class Solution {
public:
    int rotatedDigits(int N) {
        int cnt = 0;
        vector<int> dp(N+1);
        for(int i = 0; i <= N; ++i){
            if(i < 10){
                if(i == 0 || i == 1 || i == 8) dp[i] = 1;
                else if(i == 2 || i == 5 || i == 6 || i == 9){
                    cnt++;
                    dp[i] = 2;
                }
            }
            else{
                int a = dp[i/10], b = dp[i%10];
                if(a == 1 && b == 1) dp[i] = 1;
                else if(a >= 1 && b >= 1){
                    dp[i] = 2;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
