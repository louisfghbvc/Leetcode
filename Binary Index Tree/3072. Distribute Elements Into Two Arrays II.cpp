class Solution {
public:
    
    struct BIT {
        
        BIT(int n) : N(n+1), arr(n+1) {}
        
        void add(int x, int v=1) {
            for (++x; x < N; x += x&-x) 
                arr[x] += v;
        }
        
        int sum(int x) {
            int res = 0;
            for (++x; x; x -= x&-x) 
                res += arr[x];
            return res;
        }
        
        int N;
        vector<int> arr;
    };
    
    vector<int> resultArray(vector<int>& nums) {
        // goal: concate the array by rule
        // rule, greaterCount(arr, val): number of elements in arr greater than val
        
        // idea: we can use binary index tree to calculate the greater count
        // sum(val): number of element <= val
        
        
        int n = nums.size();
        
        auto distinct = nums;
        sort(distinct.begin(), distinct.end());
        distinct.erase(unique(distinct.begin(), distinct.end()), distinct.end());
        
        auto conv = [&](int x) {
            return lower_bound(distinct.begin(), distinct.end(), x) - distinct.begin();
        };
        
        vector<int> arr1, arr2;
        
        BIT tree1(distinct.size()), tree2(distinct.size());
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        tree1.add(conv(nums[0]));
        tree2.add(conv(nums[1]));
        for (int i = 2; i < n; ++i) {
            int val = conv(nums[i]);
            int cnt1 = arr1.size() - tree1.sum(val);
            int cnt2 = arr2.size() - tree2.sum(val);
            if (cnt1 > cnt2) {
                tree1.add(val);
                arr1.push_back(nums[i]);
            }
            else if (cnt2 > cnt1) {
                tree2.add(val);
                arr2.push_back(nums[i]);
            }
            else {
                if (arr1.size() > arr2.size()) {
                    tree2.add(val);
                    arr2.push_back(nums[i]);
                }
                else {
                    tree1.add(val);
                    arr1.push_back(nums[i]);
                }
            }
        }
        
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
