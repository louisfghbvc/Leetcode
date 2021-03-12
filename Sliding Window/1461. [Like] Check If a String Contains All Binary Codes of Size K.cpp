// Maintain window size with k. and hash
// O(N). 

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> st;
        int d = 0;
        for(int r = 0, l = 0; r < s.size(); ++r){
            d = d*2 + s[r]-'0';
            if(r - l >= k-1){
                st.insert(d);
                d -= (s[l++]-'0') << (k-1);
            }
        }
        return st.size() == (1<<k);
    }
};


// Same idea rolling hash
// O(N). space O(2^K).
class Solution {
public:
    constexpr static size_t N = 1<<20;
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false;
        
        bitset<N> bt;
        int val = 0, r = 0;
        int upper = 1<<(k-1);
        
        for(;r < k; ++r){
            val = val*2 + s[r]-'0';
        }

        bt[val] = 1;
        for(; r < s.size(); ++r){
            val = val - upper*(s[r-k]-'0');
            val = val*2 + s[r] - '0';
            bt[val] = 1;
        }
        return bt.count() == 1<<k;
    }
};
