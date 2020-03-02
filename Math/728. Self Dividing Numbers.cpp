//0ms 7.4MB, Brute-Force
class Solution {
public:
    bool check(int num){
        int tmp = num;
        while(tmp > 0){
            if(tmp % 10 == 0)
                return false;
            if(num % (tmp % 10))
                return false;
            tmp /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; ++i){
            if(check(i)){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
