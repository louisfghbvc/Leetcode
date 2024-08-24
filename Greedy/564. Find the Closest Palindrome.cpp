class Solution {
public:

    string getMin(string& a, vector<string>& candidate) {
        long ans = stoll(candidate[0]);
        long dif = LLONG_MAX;
        for (auto &s: candidate) {
            long val1 = stoll(a), val2 = stoll(s);
            if (val2 == val1) continue; // can be equal to itself
            if (dif > abs(val1-val2) || dif == abs(val1-val2) && val2 < ans) {
                dif = abs(val1-val2);
                ans = val2;
            }
        }
        return to_string(ans);
    }

    string nearestPalindromic(string s) {
        // goal: find next palindrome number and previous palindrome number
        // idea:
        // length is even or odd 

        // if s[i] == s[n-i] 
        // we want to change as mid as possible
        // ???..???
        // ^      ^
        //  ^  

        // change?
        // change right most
        // a b c c b c
        // a b c b c a => a b c c b a
        //          

        // if no change -> means original is palindrome -> +1 or -1
        // need care! 
        // 989 -> 999
        // 999 -> 1001
        // 898 -> 909 or 888

        // 808 -> 818 or 797

        // only the case 0 and 9 need to consider
        // otherwise => -1
        // ?88?

        // 0 -> 1
        // 101 -> 99

        // 99 -> 101
        // 9 -> 11 -> 9

        // 202 => 

        // 999 -> 1001

        // speical is 999 or 1001 ...

        // idea2:
        // after WA 2 times.
        // we can make it general -> lets find 9999, 101, first
        // wtf.
        // try all possible no matter change or not
        // generate 99, 11 pattern
        // and after we make original string to palidrome, we also need to find prev and next

        bool isChange = false;
        int n = s.size();
        string ori = s;
        string s99 = n > 1 ? string(n-1, '9') : "9";
        string s11 = n > 1 ? string(1, '1') + string(n-1, '0') + string(1, '1') : "11";

        for (int i = 0; i < n; ++i) {
            if (s[i] != s[n-i-1]) {
                s[n-i-1] = s[i];
                isChange = true;
            }
        }

        vector<string> tmp = {s99, s11, s};

        // do -1
        string left = s.substr(0, (n+1)/2);
        string sub1 = to_string(stoll(left)-1);
        sub1 += string(sub1.rbegin()+(n&1), sub1.rend());
        tmp.push_back(sub1);

        // do +1
        string add1 = to_string(stoll(left)+1);
        add1 += string(add1.rbegin()+(n&1), add1.rend());
        tmp.push_back(add1);
        
        return getMin(ori, tmp);
    }
};
