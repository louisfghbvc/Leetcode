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
