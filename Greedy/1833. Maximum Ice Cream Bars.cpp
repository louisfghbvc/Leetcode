// Just greedy. O(NlogN). sort and always grab smallest.

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int buy = 0;
        long sum = 0;
        for(int x: costs){
            if(sum + x <= coins){
                sum += x;
                buy++;  
            }
            else break;
        }
        return buy;
    }
};
