//0ms 7.3MB
class Solution {
public:
    bool isC(char c){
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'; 
    }
    string reverseOnlyLetters(string S) {
        for(int l = 0, r = S.size() - 1; l <= r; ++l, --r){
            while(!isC(S[l]) && l + 1 < S.size()) l++;
            while(!isC(S[r]) && r - 1 >= 0) r--;
            if(l <= r)
                swap(S[l], S[r]);
        }
        return S;
    }
};
