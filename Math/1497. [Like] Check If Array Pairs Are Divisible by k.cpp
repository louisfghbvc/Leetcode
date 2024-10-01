// use remainer if even then can pair.
// special case is check mod is zero.
// O(N+K).

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // goal: build the pairs such that n/2 pairs sum divisible by k
        
        // idea:
        // k = 5
        // 0 1 2 3 4 => (1,4),(2,3)
        
        // k = 4
        // 0 1 2 3

        // group the number by mod k
        // record the cnt of k

        // arr[i] can be negative!

        vector<int> cnt(k);
        for (int x: arr)
            cnt[(x%k+k)%k]++;
        
        if (cnt[0] & 1) return false;
        if (k % 2 == 0) {
            if (cnt[k/2] & 1) return false;
        }
        for (int i = 1; i < k; ++i) {
            if (cnt[i] != cnt[k-i]) return false;
        }
        return true;
    }
};

// Follow up
// What about if k is large?
// using hashtable
// TC: O(n)

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // goal: build the pairs such that n/2 pairs sum divisible by k
        
        // idea:
        // k = 5
        // 0 1 2 3 4 => (1,4),(2,3)
        
        // k = 4
        // 0 1 2 3

        // group the number by mod k
        // record the cnt of k

        // arr[i] can be negative!

        unordered_map<int, int> cnt;
        for (int x: arr)
            cnt[(x%k+k)%k]++;
        
        if (cnt[0] & 1) return false;
        if (k % 2 == 0) {
            if (cnt[k/2] & 1) return false;
        }

        for (auto &[m, f]: cnt) {
            if (m == 0) continue;
            if (!cnt.count(k-m) || cnt[k-m] != f) return false;
        }

        return true;
    }
};
