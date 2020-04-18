//Tricky. Just find minimum prefix sum, reverse + 1.
//So that can let step by step be positive.
//0ms-4ms 7.4MB
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, min_sum = 0;
        for(auto n: nums){
            sum += n;
            min_sum = min(sum, min_sum);
        }
        return -min_sum + 1;
    }
};
