class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto &s: details) {
            int age = (s[11]-'0')*10+(s[12]-'0');
            ans += age > 60;
        }
        return ans;
    }
};
