// O(N). greedy + enum all case.
// enum b to z. B need change. and A's character if big put to smallest 'a'.

class Solution {
public:
    int minCharacters(string a, string b) {
        int m = a.size(), n = b.size();
        
        vector<int> fre1(26), fre2(26);
        for(char c: a) fre1[c-'a']++;
        for(char c: b) fre2[c-'a']++;
        
        int mn = 1e9;
        // condition 3
        for(int i = 0; i < 26; ++i){
            mn = min(m+n-fre1[i]-fre2[i], mn);
        }
        
        // condition 1, 2
        for(int i = 1; i < 26; ++i){
            int mov = n;
            for(int k = i; k < 26; ++k) mov -= fre2[k];

            vector<int> tmp = fre1;
            for(int k = i; k < 26; ++k){
                mov += tmp[k];
                tmp[0] += tmp[k];
            }
            mn = min(mov, mn);
        }
        // cout << "cond 1: " << mn << "\n";


        for(int i = 1; i < 26; ++i){
            int mov = m;
            for(int k = i; k < 26; ++k) mov -= fre1[k];

            vector<int> tmp = fre2;
            for(int k = i; k < 26; ++k){
                mov += tmp[k];
                tmp[0] += tmp[k];
            }
            mn = min(mov, mn);
        }
        // cout << "cond 2: " << mn << "\n";
        
        
        return mn;
    }
};
