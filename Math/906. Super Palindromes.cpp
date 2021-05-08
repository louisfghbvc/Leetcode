class Solution {
public:
    
    bool isP(string s){
        for(int i = 0; i < s.size() / 2; ++i)
            if(s[i] != s[s.size() - i - 1]) return false;
        return true;
    }
    
    int superpalindromesInRange(string left, string right) {
        // so first. generate 1e9 palindrome number
        // and we just need to to enumerate half = 1e4 enough
        
        long lv = stoll(left), rv = stoll(right);
        
        vector<long> pal = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(int i = 1; i <= 8000; ++i){
            string l = to_string(i), r = l;
            reverse(r.begin(), r.end());
            pal.push_back(stoll(l + r));
            for(char d = '0'; d <= '9'; ++d)
                pal.push_back(stoll(l + string(1, d) + r));
        }
        
        
        int cnt = 0;
        for(auto &v: pal){
            long super = v*v;
            if(super <= rv && super >= lv && isP(to_string(super))) cnt++;
        }
        
        return cnt;
    }
};
