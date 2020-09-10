// O(N). Game. Tricky. One Pass. Secret Increment. Guess Decrease. So. If Secret counter neg. means guess appear before. add 1.
// If Guess counter pos, means Secret appear before. add 1

class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0, n = guess.size();
        int cnt[10] = {};
        for(int i = 0; i < n; ++i){
            if(secret[i] == guess[i]) a++;
            else{
                if(cnt[secret[i]-'0'] < 0) b++;
                if(cnt[guess[i]-'0'] > 0) b++;
                cnt[secret[i]-'0']++;
                cnt[guess[i]-'0']--;
            }
        }
        return to_string(a) + 'A' + to_string(b) + 'B';
    }
};

// O(N). two hash table. one for secret, other for guess. B add min.


// O(N^2), BF.
