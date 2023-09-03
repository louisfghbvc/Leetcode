class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; ++i) {
            string s = to_string(i);
            if (s.size() & 1) continue;
            int a = 0, b = 0;
            for (int j = 0; j < s.size()/2; ++j) {
                a += s[j]-'0';
                b += s[j+s.size()/2]-'0';
            }
            ans += a == b;
        }
        return ans;
    }
};
