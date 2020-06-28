// use remainer if even then can pair.
// special case is check mod is zero.
// O(N). Trick

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> fre;
        for(auto &x: arr){
            fre[(x % k + k) % k]++;
        }
        
        for(int i = 1; i < k; ++i){
            if(fre[i] != fre[k-i]) return false;
        }
        
        return fre[0] % 2 == 0;
    }
};
