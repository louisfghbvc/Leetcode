// Rolling Hash. Now I totally understand what this algorithm do.
// thr trick is binary search the length.
// and this Rabin-Karp algorithm can find all length == k substring use sliding window concept.
// so find all substring length == k is O(N).
// and unordered_map is bucket. maybe collision, so use vector<int> save all posiible.
// total time O(NlogN)

class Solution {
public:
    int mod = 1e9+7;
    string ans;
    string valid(int len, string &s){ // rolling hash
        if(len == 0) return "";
        
        long power = 1, p = 0; // pow(power, len-1), pattern hash
        for(int i = 0; i < len-1; ++i){ 
            power = (power*26) % mod; 
        }
        
        for(int i = 0; i < len; ++i){
            p = (p*26 + (s[i]-'a')) % mod;
        }
        
        unordered_map<int, vector<int>> mp;
        mp[p] = vector<int>(1, 0);
        
        for(int i = len; i < s.size(); ++i){
            // rehash, subtract sign and add least
            p = (((p-(s[i-len]-'a')*power)*26 + s[i]-'a') % mod + mod) % mod;

            if(!mp.count(p)){
                mp[p] = vector<int>(1, i-len+1);
            }
            else{
                // now start index is i-len+1
                for(auto& start: mp[p]){
                    if(s.substr(start, len).compare(s.substr(i-len+1, len)) == 0)
                        return s.substr(start, len);
                }
                mp[p].push_back(i-len+1);
            }
        }
        
        return "";
        
    }
    string longestDupSubstring(string S) {
        ans = "";
        int l = 0, r = S.size()-1;
        while(l <= r){
            int mid = (l+r)>>1;
            string tmp = valid(mid, S);
            if(tmp.empty()){
                r = mid - 1;
            }
            else{
                if(ans.size() < tmp.size())
                    ans = tmp;
                l = mid + 1;
            }
        }
        return ans;
    }
};
