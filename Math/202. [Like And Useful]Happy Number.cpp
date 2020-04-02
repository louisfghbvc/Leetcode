//tricky cycle finding algorithm
class Solution {
public:
    int nxt(int n){
        int ans = 0;
        while(n > 0){
            int t = n%10;
            ans += t*t;
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = nxt(slow);
            fast = nxt(fast);
            fast = nxt(fast);
        }while(slow != fast);
        return slow == 1;
    }
};
