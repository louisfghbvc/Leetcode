// observe the appeal change
// only change the range between [l, r] where l is s[i] position
// O(N)
class Solution {
public:
    long long appealSum(string s) {
        // goal: cal appeal of all substring of s
        // idea: brute force approach is n^2 -> how to optimize?
        
        // a: {0, 4}
        // b: {1,  2}
        // c: {3}
        // abbca
        // 12233 -> 11
        //  1123 -> 11 - 3
        //   123 -> 11 - 3 - 1 - 0 - 1
        //    12 -> 11 - 3 - 1 - 0 - 1 - 3
        //     1 
        
        int n = s.size();
        vector<queue<int>> idx(26);
        for (int i = 0; i < n; ++i)
            idx[s[i]-'a'].push(i);
                
        long total = 0; // first time
        unordered_set<char> appeal;
        for (int i = 0; i < n; ++i) {
            appeal.insert(s[i]);
            total += appeal.size();
        }

        long res = total;
        for (int i = 0; i < n; ++i) {
            idx[s[i]-'a'].pop();
            total -= 1;
            if (idx[s[i]-'a'].size()) { // next a index?
                int j = idx[s[i]-'a'].front();
                total -= j - i - 1;
            }
            else {
                total -= n - i - 1;
            }
            res += total;
        }
        
        return res;
    }
};


// same idea as above
// only contribution in the differnt beginning, last can be the same
// just calculate the nubmer of different previous
// O(N)

class Solution {
public:
    long long appealSum(string s) {
        vector<int> idx(26, -1);
        
        int n = s.size();
        long res = 0;
        for (int i = 0; i < n; ++i) {
            int pre = idx[s[i]-'a'];
            idx[s[i]-'a'] = i;
            res += 1LL * (i - pre) * (n - i);
        }
        
        return res;
    }
};


