// Prefix map + bitmask. so use prefix sum, and we want find that if there is a prefix that can make this string odd at most once.
// O(N).

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long res = 0;
        unordered_map<int, long> mp;
        mp[0] = 1;
        
        int val = 0;
        for(int r = 0; r < word.size(); ++r){
            val ^= (1 << (word[r] - 'a'));
            for(int k = 0; k < 10; ++k)
                if(mp.count(val ^ (1<<k))) res += mp[val ^(1<<k)];
            res += mp[val]++;
        }
        
        return res;
    }
};
