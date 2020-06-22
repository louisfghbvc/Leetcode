// first calculate diff, and find lowbit(any bit is ok).
// use lowbit to divide nums to 2 group.
// O(N). two pass, very trick

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for(auto&x: nums) diff ^= x;
        diff &= -diff; // lowbit;
        int a = 0, b = 0;
        for(auto&x: nums){
            if(x & diff){
                a ^= x;
            }
            else b ^= x;
        }
        return {a, b};
    }
};
