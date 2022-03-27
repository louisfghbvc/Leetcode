class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        // goal: for each query, return the number that is kth palindrome where length is intLength
        // len = 1, 1~9   
        // len = 2, 11~99 starting from 1
        // len = 3, 101~999 starting from 10
        // len = 4, 1001~9999 starting from 10
        
        // idea: enumerate the first half palindrome
        // 101, 111
        
        vector<long long> ans;
        
        for (int q: queries) {
            int bit = (intLength-1) / 2;
            long base = pow(10, bit);
            
            if (base + q - 1 >= base * 10) {
                ans.push_back(-1);
                continue;
            }
            
            string first = to_string(base + q - 1);
            
            if (intLength & 1) { // odd
                string second = first.substr(0, first.size()-1);
                reverse(second.begin(), second.end());
                ans.push_back(stoll(first + second));
            }
            else { // even
                string second = first;
                reverse(second.begin(), second.end());
                ans.push_back(stoll(first + second));
            }
            
        }
        
        return ans;
    }
};
