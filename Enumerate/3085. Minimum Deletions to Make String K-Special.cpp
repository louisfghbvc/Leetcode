class Solution {
public:
    int minimumDeletions(string word, int k) {
        // goal:
        // we need to make word k-special
        // k-special?
        // |fre[word[i]]-fre[word[j]]| <= k

        // idea:
        // aabbc, k=2
        // aabbc, k=0
        // aaac, k=1

        // aaa bbb c
        // check max fre vs min fre => when > k
        // we always delete maximum or delete all minimum

        // think two pointers
        // 1,2,3,5 => k=2 
        // ^     ^

        // we can just two pointer and always merge cnt[i] to cnt[i-1] when cnt[i]-cnt[j] > k
        // enumerate all left point (26)
        // count -> O(n)
        
        vector<int> cnt(26);
        for (char c: word)
            cnt[c-'a']++;

        sort(cnt.begin(), cnt.end());
        
        // aabcaba, k=0
        // a b c
        // 4 2 1
        // 1,2,4, ch=1+3

        // wrong =>
        // ahahnhahhah, k=1
        // a h n
        // 4 6 1

        // 1 4 6 (3+5)
        //   4 6 (1+1)
        //     6 (5) 

        // we no need to change to previous
        // cnt[i]-cnt[i-1] > k
        // cnt[i]-cnt[i-1] <= k

        // dabdcbdcdcd
        // a b c d, k=2
        // 1 

        int ans = word.size(), pre = 0;
        for (int i = 0; i < 26; ++i) {
            int change = 0;
            for (int j = i; j < 26; ++j) {
                // need erase
                if (i != j && cnt[j] - cnt[i] > k) {
                    change += cnt[j] - cnt[i] - k;
                }
            }
            ans = min(ans, change + pre);
            pre += cnt[i]; // erase all left
        }
        return ans;
    }
};
