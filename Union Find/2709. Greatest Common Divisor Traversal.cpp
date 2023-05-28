class Solution {
public:
    
    vector<int> p;
    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y];
        p[y] = x;
    }
    
    bool canTraverseAllPairs(vector<int>& nums) {
        // goal: for each pairs, try to get a path gcd is not 1
        // idea:
        // if number cover values, 6: 2,3,6
        // use union find 
        
        unordered_map<int, int> ind; // val -> index
        
        int n = nums.size();
        p = vector<int>(n, -1);
        
        // TC: O(n * sqrt(x))
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            for (long p = 2; p*p <= nums[i]; ++p) {
                if (x % p == 0) {
                    if (!ind.count(p))
                        ind[p] = i;
                    else
                        uni(ind[p], i);
                    while (x % p == 0) x /= p;
                }
            }
            if (x != 1) { // not prime
                if (!ind.count(x))
                    ind[x] = i;
                else
                    uni(ind[x], i);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (p[i] < 0 && -p[i] == n) return true;
        }
        
        return false;
    }
};
