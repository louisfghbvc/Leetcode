// simulate 

class Solution {
public:
    int distMoney(int money, int children) {
        // goal: maximum the 8 dollar
        // idea: 
        if (children > money) return -1;
        money -= children;
        
        vector<int> arr(children, 1);
        for (int &x: arr) {
            if (money >= 7) x = 8, money -= 7;
            else {
                x += money; 
                money = 0;
                break;
            }
        }
        
        if (money) {
            arr.back() += money;
        }
        
        for (int i = 0; i < children; ++i) {
            if (arr[i] == 4) {
                if (arr.back() == 4) return count(arr.begin(), arr.end(), 8) - 1;
            }
        }
        
        return count(arr.begin(), arr.end(), 8);
    }
};
