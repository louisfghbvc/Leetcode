class Solution {
public:
    
    // e.g 
    // 0230 vs 
    // 3020
    
    // 1 2 3 4
    // 3 4 2 1 -> 
    // 4 3 2 1 -> ok
    
    // 4 diff
    // 3 cases:
    // a a b b => (1,2) (3,4)
    // a b a b => (1,3) (2,4)
    // a b b a => (1,4) (2,3)
    
    // 3 diff
    // (1,2) (2,3)
    // (1,2) (3,1)
    // (1,3) (3,2)
    
    int countPairs(vector<int>& nums) {
        // goal: find the pairs such that is almost equal, swap at most twice
        // idea:
        // brute force -> TLE
        
        // consider enumerate the swap nums?
        // O(n * m^4)
        
        // 012
        // 021
        
        int n = nums.size();
        
        // init
        vector<string> tmp; 
        int sz = 0;
        for (int x: nums) {
            string s = to_string(x);
            tmp.push_back(s);
            sz = max((int)s.size(), sz);
        }
        // padding zero
        for (auto &s: tmp) {
            reverse(s.begin(), s.end());
            s += string((int)sz - (int)s.size(), '0');
            reverse(s.begin(), s.end());
        }
        
        int ans = 0; 
        unordered_map<string, int> cnt;
        for (auto &s: tmp) {
            unordered_set<string> poss;
            // 0
            poss.insert(s);
            // 1
            for (int p1 = 0; p1 < sz; ++p1) {
                for (int p2 = p1+1; p2 < sz; ++p2) {
                    swap(s[p1], s[p2]);
                    poss.insert(s);
                    swap(s[p1], s[p2]);
                }
            }
            // 2
            for (int p1 = 0; p1 < sz; ++p1) {
                for (int p2 = p1+1; p2 < sz; ++p2) {
                    for (int p3 = p2+1; p3 < sz; ++p3) {
                        swap(s[p1], s[p2]);
                        swap(s[p2], s[p3]);
                        poss.insert(s);
                        swap(s[p2], s[p3]);
                        swap(s[p1], s[p2]);
                        
                        swap(s[p1], s[p2]);
                        swap(s[p1], s[p3]);
                        poss.insert(s);
                        swap(s[p1], s[p3]);
                        swap(s[p1], s[p2]);
                        
                        swap(s[p1], s[p3]);
                        swap(s[p2], s[p3]);
                        poss.insert(s);
                        swap(s[p2], s[p3]);
                        swap(s[p1], s[p3]);
                    }
                }
            }
            
            for (int p1 = 0; p1 < sz; ++p1) {
                for (int p2 = p1+1; p2 < sz; ++p2) {
                    for (int p3 = p2+1; p3 < sz; ++p3) {                    
                        for (int p4 = p3+1; p4 < sz; ++p4) {
                            swap(s[p1], s[p2]);
                            swap(s[p3], s[p4]);
                            poss.insert(s);
                            swap(s[p3], s[p4]);
                            swap(s[p1], s[p2]);
                            
                            swap(s[p1], s[p3]);
                            swap(s[p2], s[p4]);
                            poss.insert(s);
                            swap(s[p2], s[p4]);
                            swap(s[p1], s[p3]);
                            
                            swap(s[p1], s[p4]);
                            swap(s[p2], s[p3]);
                            poss.insert(s);
                            swap(s[p2], s[p3]);
                            swap(s[p1], s[p4]);
                        }
                    }
                }
            }     
            
            // update
            for (auto &t: poss)
                ans += cnt[t];
            cnt[s]++;
        }
        
        return ans;
    }
};
