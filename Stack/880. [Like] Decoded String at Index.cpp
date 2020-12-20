// O(N). Stack idea. so just multiply until len >= K.
// And then just backward to figure that what char is.
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long len = 0, i;
        for(i = 0; len < K; ++i){
            if(isalpha(S[i])) len++;
            else len *= S[i] - '0';
        }
        
        while(i--){
            if(isalpha(S[i])){
                if(K % len == 0) return string(1, S[i]);
                len--;
            }
            else{
                len /= S[i] - '0';
                K %= len;
            }
        }
        
        return "";
    }
};

// O(N). Clean Recursive idea. DFS.
class Solution {
public:
    string decodeAtIndex(string &S, int K, long len = 0) {
        for(char c: S){
            if(isalpha(c)){
                len++;
                if(len == K) return string(1, c);
            }
            else{
                if(len*(c-'0') >= K) return decodeAtIndex(S, K % len == 0 ? len : K%len);
                len *= c - '0';
            }
        }
        return "";
    }
};
