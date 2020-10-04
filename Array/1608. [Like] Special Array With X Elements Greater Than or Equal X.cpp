// O(N^2). BF.
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int fre[1005] = {};
        for(int x: nums){
            for(int i = 0; i <= x; ++i)
                fre[i]++;
        }
        for(int i = 0; i <= 1000; ++i){
            if(fre[i] == i) return i;
        }
        return -1;
    }
};

// Use dp concept.
// O(N). next big is remain to now big. suffix.

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int fre[1005] = {};
        for(int x: nums)
            fre[x]++;
        for(int i = 999; i >= 0; --i){
            fre[i] += fre[i+1];
            if(fre[i] == i) return i;
        }
        return -1;
    }
};
