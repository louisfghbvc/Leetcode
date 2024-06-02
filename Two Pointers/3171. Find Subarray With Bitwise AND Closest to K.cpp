// Approach 1. 
class Solution {
public:
    
    void add(vector<int> &bit, int x, int v) {
        for (int i = 0; i < 30; ++i) {
            if (x >> i & 1) {
                bit[i] += v;
            }
        }
    }
    
    int get(vector<int> &bit, int len) {
        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            if (bit[i] == len) {
                ans |= 1<<i;
            }
        }
        return ans;
    }
    
    int minimumDifference(vector<int>& nums, int k) {
        // goal: find the minimum abs AND with k
        // idea:
        // two pointers + binary search the ans
        // 6,5,4 => 4, k=1, f=2
        
        int n = nums.size();
        
        auto good = [&](int f) -> bool {
            vector<int> tmp(30);
            for (int r = 0, l = 0; r < n; ++r) {
                add(tmp, nums[r], 1);
                while (l < r && abs(get(tmp, r-l+1) - k) > f) {
                    if (get(tmp, r-l+1) < k) add(tmp, nums[l++], -1);
                    else break;
                }
                if (abs(get(tmp, r-l+1)-k) <= f)
                    return true;
            }    
            return false;
        };
        
        int l = 0, r = 1e9;
        int ans = 1e9;
        while (l <= r) {
            int m = (l+r)/2;
            if (good(m)) ans = m, r = m-1;
            else l = m+1;
        }
        return ans;
    }
};

// Approach 2. Tricky of monotonic AND/OR/GCD
class Solution {
public:
    
    int minimumDifference(vector<int>& nums, int k) {
        // goal: find the minimum abs AND with k
        // idea:
        // consider each index as right
        // we only have 30 different AND/GCD/OR value... to the left
        

        unordered_set<int> pre;
        int ans = 1e9;
        for (int x: nums) {
            unordered_set<int> next = {x};
            for (int p: pre)
                next.insert(p & x);
            for (int p: next) 
                ans = min(ans, abs(p-k));
            swap(pre, next);
        }        
        
        return ans;
    }
};


// Approach3. Tricky of monotonic AND/OR/GCD with optimized with array...
class Solution {
public:
    
    int minimumDifference(vector<int>& nums, int k) {
        // goal: find the minimum abs AND with k
        // idea:
        // consider each index as right
        // we only have 30 different AND/GCD/OR value... to the left
        
        vector<int> pre;
        int ans = 1e9;
        for (int x: nums) {
            // pre is increasing
            for (int i = 0; i < pre.size(); ++i)
                pre[i] &= x;
            pre.push_back(x);
            pre.erase(unique(pre.begin(), pre.end()), pre.end());
            for (int p: pre) 
                ans = min(ans, abs(p-k));
        }        
        
        return ans;
    }
};
