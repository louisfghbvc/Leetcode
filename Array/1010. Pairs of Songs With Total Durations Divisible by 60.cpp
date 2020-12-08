// O(N). Space O(1).
// Rolling prefix.
// just like two sum. pr + pl = 60. so find 60-pr
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int mp[60] = {};
        int res = 0;
        for(int x: time){
            x %= 60;
            res += mp[(60-x)%60];  
            mp[x]++;
        }
        return res;
    }
};

// O(N). use map
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;
        int res = 0;
        for(int x: time){
            x %= 60;
            res += mp[(60-x)%60];  
            mp[x]++;
        }
        return res;
    }
};
