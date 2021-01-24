// Math. so find pattern.
// Remove last floor, try to build a smaller.

class Solution {
public:
    int minimumBoxes(int n) {
        int sum = 0, floor = 0, i = 0;
        while(sum < n){
            ++i;
            floor += i;
            sum += floor;
        }
        if(sum == n) return floor;
        
        sum -= floor;
        floor -= i;
        i = 0;
        while(sum < n){
            ++i;
            sum += i;
        }
        return floor+i;
    }
};
