//44ms 8.2MB
class Solution {
public:
	void dfs(int d, int &n, int &used, int &res){
		if(d == n){
			return;
		}
		for(int i = (d == 0) ? 1 : 0; i <= 9; ++i){
			if(used & (1<<i)) continue;
			res++;
            used |= (1<<i);
			dfs(d + 1, n, used, res);
            used ^= (1<<i);
		}
	}
    int countNumbersWithUniqueDigits(int n) {
        int cnt = 0, used = 0;
        dfs(0, n, used, cnt);
        return cnt + 1;
    }
};
