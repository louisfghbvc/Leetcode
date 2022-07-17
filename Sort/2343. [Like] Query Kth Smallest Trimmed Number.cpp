// Solution1: just simulate

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        // goal: for each query, find the kth smallest number, where trim righmost digits
        // trim: remain the rightmost digits
        
        // idea: sort the string array -> wrong
        // idea2: simulate the process -> each queries
        
        int n = nums.size();
        vector<int> res;
        
        // O(N)
        for (auto &q: queries) {
            
            // sort the array
            // O(NlogNk)
            vector<int> order(n);
            iota(order.begin(), order.end(), 0);
            sort(order.begin(), order.end(), [&](auto &i, auto &j) {
                for (int k = (int)nums[0].size()-q[1]; k < nums[0].size(); ++k) {
                    if (nums[i][k] < nums[j][k]) return true;
                    else if (nums[i][k] > nums[j][k]) return false;
                }
                return i < j;  
            });
            
            res.push_back(order[q[0]-1]);
        }
        
        return res;
    }
};


// Solution2: radix sort
class Solution {
public:
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        // goal: for each query, find the kth smallest number, where trim righmost digits
        // trim: remain the rightmost digits
        // idea: radix sort
        
        int n = nums.size();
        int length = nums[0].size();
        
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        
        auto radix_sort = [&](int p) -> void {
            vector<int> nxt;
            vector<int> cnt[10];
            for (int i: order) 
                cnt[nums[i][p]-'0'].push_back(i);
            
            for (int i = 0; i < 10; ++i) {
                for (int j: cnt[i])
                    nxt.push_back(j);
            }
            order = nxt;
        };
        
        vector<vector<int>> table;
        
        for (int i = length-1; i >= 0; --i) {
            radix_sort(i);
            table.push_back(order);
        }
        
        vector<int> res;
        for (auto &q: queries)
            res.push_back(table[q[1]-1][q[0]-1]);
        return res;
    }
};
