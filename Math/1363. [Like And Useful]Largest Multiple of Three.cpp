//8ms 9.7MB
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int cnt[10] = {};
        for(int d : digits)
            cnt[d]++;
        int remain1 = cnt[1] + cnt[4] + cnt[7];
        int remain2 = cnt[2] + cnt[5] + cnt[8];
        int remainsum = (remain1 + remain2 * 2) % 3;
        if(remainsum == 1){
            if(remain1 >= 1) remain1--;
            else remain2 -= 2;
        }
        else if(remainsum == 2){
            if(remain2 >= 1) remain2--;
            else remain1 -= 2;
        }
        
        string ans = "";
        for(int d = 9; d >= 0; --d){
            if(d % 3 == 0) 
                while(cnt[d]-- > 0) 
                    ans += (d + '0');
            else if(d % 3 == 1) 
                while(cnt[d]-- > 0 && remain1-- > 0) 
                    ans += (d + '0');
            else 
                while(cnt[d]-- > 0 && remain2-- > 0) 
                    ans += (d + '0');
        }
        
        if(ans.size() > 0 && ans[0] == '0') return "0";
        
        return ans;
    }
};
