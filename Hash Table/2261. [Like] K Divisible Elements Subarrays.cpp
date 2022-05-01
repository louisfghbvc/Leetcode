// simple but O(N^3up)
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        // goal: number of distinct subarrays such that have at most k elements
        // in subarray that divisible by p
        
        // idea: two pointers, from current position to extend
        // O(N^2) -> how to avoid duplicate
        
        // try brute force?
        
        int n = nums.size();
        set<vector<int>> st; // N^3logN? compare -> n
        // hash to string : the length of digits is 3*N
        for (int i = 0; i < n; ++i) {
            vector<int> tmp;
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                cnt += nums[j] % p == 0;
                if (cnt > k) break;
                tmp.push_back(nums[j]);
                st.insert(tmp);
            }
        }
        
        return st.size();
    }
};

// O(N^2) use trie
// inspired by votrubac
class Solution {
public:
    
    struct trie {
        unordered_map<int, trie*> child; // child node
        int cnt = 0;
        int insert(vector<int> &nums, int i, int k, int p) {
            if (i == nums.size() || k-(nums[i]%p==0) < 0) return 0;
            int x = nums[i];
            if (child[x] == nullptr)
                child[x] = new trie();
            int first_appear = ++child[x]->cnt == 1;
            return first_appear + child[x]->insert(nums, i+1, k-(x%p==0), p);
        }
    };
    
    int countDistinct(vector<int>& nums, int k, int p) {
        // idea: use trie
        
        int n = nums.size();
        int res = 0;
        trie root;
        for (int i = 0; i < n; ++i) {
            res += root.insert(nums, i, k, p);
        }
        
        return res;
    }
};
