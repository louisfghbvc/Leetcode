//0ms 8.3MB
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
   	 	if(n == 0) return 1;
    	if(n == 1) return 10;
    	int cnt = 9, d = 9, mask = 9;
    	while(--n > 0){
    		cnt += d * mask;
    		d = d * mask;
    		mask--;
    	}
    	return cnt + 1;
    }
};


// digit dp. O(N2^N).
class Solution {
public:
    int n;
    int dp[9][1024][2];
    int dfs(int i = 0, int used = 0, bool lz = 1){
        if(i == n) return 1;
        int &res = dp[i][used][lz];
        if(res != -1) return res;
        res = 0;
        for(int d = 0; d <= 9; ++d){
            if(used >> d & 1) continue;
            int nused = used | (1<<d);
            if(lz && d == 0) // leading zero no need to set
                res += dfs(i+1, used, 1);
            else
                res += dfs(i+1, nused, 0);
        }
        return res;
    }
    
    int countNumbersWithUniqueDigits(int n) {
        memset(dp, -1, sizeof dp);
        this->n = n;
        return dfs();
    }
};
