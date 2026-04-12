class Solution {
public:
    int longestBalanced(string s) {
        // goal: find the maximum length of balance string by swap at most one 

        // idea:
        // length must be even
        // if the length is even and the abs(cnt1-cnt0) <= 1, we should check out 
        // if outside has enough char
        // [0 0 0 1 1 1 1 1],  1 1 1 1

        // we could guess the length, binary search => wrong, not really monotone
        
        // use prefix sum to do that
        // how to do at most 1 swap?
        // 1.. [110000] ....
        // we need to make sure we have 1 to swap
        // we need to record the 1 index if not we cant do +2
        // consider the case
        // [1100110000]
        //      l
        // we need to record 3 state
        // longest pos
        // appear 1 pos
        // appear 0 pos

        // 3 case
        // pre[R]- pre[L-1] = 0
        // pre[R]- pre[L-1] = 2 => need one in left
        // pre[R]- pre[L-1] = -2

        // missing some case we could use one in right
        // just check out the prefix range has all one or not

        int n = s.size();
        int totZero = 0, totOne = 0;
        vector<int> cnt1(n+1, 0), cnt0(n+1, 0);
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '0') totZero++;
            else totOne++;
            cnt0[i+1] = cnt0[i] + (c=='0');
            cnt1[i+1] = cnt1[i] + (c=='1');
        }

        unordered_map<int, int> mp, mpOne, mpZero;
        mp[0] = -1;

        int pre = 0;
        int ans = 0;
        bool hasOne = false, hasZero = false;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            pre += c == '0' ? 1 : -1;
            if (c == '1') hasOne = true;
            if (c == '0') hasZero = true;

            // no swap
            if (mp.count(pre)) {
                ans = max(ans, i - mp[pre]);
            }
            else {
                mp[pre] = i;
            }

            // +2, check right one first
            if (mp.count(pre-2)) {
                int p = mp[pre-2];
                int one = cnt1[i+1] - cnt1[p+1];
                if (one < totOne)
                    ans = max(ans, i-p);
                else if (mpOne.count(pre - 2))
                    ans = max(ans, i - mpOne[pre-2]);
            }
            
            // -2, use zero in right
            if (mp.count(pre+2)) {
                int p = mp[pre+2];
                int zero = cnt0[i+1] - cnt0[p+1];
                if (zero != totZero)
                    ans = max(ans, i-p);
                else if (mpZero.count(pre + 2))  // -2, use zero in left
                    ans = max(ans, i - mpZero[pre+2]);   
            }            

            // update map
            if (!mpOne.count(pre) && hasOne)
                mpOne[pre] = i;
            if (!mpZero.count(pre) && hasZero)
                mpZero[pre] = i;
        }

        return ans;
    }
};
