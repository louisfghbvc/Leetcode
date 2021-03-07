// O(N). Just sum and calculate diff.
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = 0;
        for(int x: nums){
            sum += x;
        }
        long diff = goal - sum;
        long res = 0;
        if(diff % limit) res++;
        return res + abs(diff / limit);
    }
};
