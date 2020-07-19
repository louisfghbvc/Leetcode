// Just Simulate. Nothing special

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        while(numBottles >= numExchange){
            res += numBottles/numExchange;
            int nxt = numBottles%numExchange;
            numBottles/=numExchange;
            numBottles += nxt;
        }
        return res;
    }
};
