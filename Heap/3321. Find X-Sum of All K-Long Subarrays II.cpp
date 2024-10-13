class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        // goal: find the top x sum
        
        // idea:
        // brute force not work, need very fast way.
        // consider the add a element/remove a element
        
        // consider add
        // x = 2
        // [1, 1, 2, 2, 3, 4]
        // [1]
        
        // fre[0] = {1,2,3,4}
        // fre[1] = {1}
        // set<pair<int, int>> topX, other
        
        // fre => set, we will move from set
        
        // maintain two set
        
        int n = nums.size();
        
            
        using T = pair<long, long>;
        set<T> topX, noTopX; // {fre, val}
        long right = 0;
        
        unordered_map<int, int> fre;
        
        auto bal = [&]() -> void {
            if (topX.size() > x) {
                // cout << "balance rem" << ' ' << topX.begin()->first << ' ' << topX.begin()->second << '\n';
                right -= topX.begin()->first*topX.begin()->second;
                noTopX.insert(*topX.begin());
                topX.erase(topX.begin());
            }
            if (topX.size() < x && noTopX.size()) {
                // cout << "balance add" << ' ' << noTopX.rbegin()->first << ' ' << noTopX.rbegin()->second << '\n';
                right += noTopX.rbegin()->first*noTopX.rbegin()->second;
                topX.insert(*noTopX.rbegin()); 
                noTopX.erase(prev(noTopX.end()));
            }
        };
        
        auto insert = [&](long x, long f) -> void {
            noTopX.insert({f, x});
    
            // move left -> right
            // cout << "insert " << ' ' << noTopX.rbegin()->first << ' ' << noTopX.rbegin()->second << '\n';
            right += noTopX.rbegin()->first*noTopX.rbegin()->second;
            topX.insert(*noTopX.rbegin()); 
            noTopX.erase(prev(noTopX.end()));
            bal();
        };
        
        auto remove = [&](const T& val) -> void {
            // cout << "try remove " << val.first << ' ' << val.second << '\n';
            
            auto it = topX.find(val);
            if (it != topX.end()) {
                // cout << "remove " << ' ' << it->first << ' ' << it->second << '\n';
                right -= it->first*it->second;
                topX.erase(it);
            }
            else {
                noTopX.erase(val);
            }
            bal();
        };
       
        auto update = [&](int x, int op=1) -> void {
            if (op == 0) { // init
                fre[x] = 0;
                insert(x, 0);
            }
            else if (op == 1) { // add
                // cout << x << ' ' << fre[x] << endl;
                remove(make_pair(fre[x], x));
                fre[x]++;
                insert(x, fre[x]);
            }
            else { // remove
                remove(make_pair(fre[x], x));
                fre[x]--;
                insert(x, fre[x]);
            }
        };
        
        
        // init
        set<int> tot(nums.begin(), nums.end());
        for (int x: tot)
            update(x, 0);
        
        vector<long long> res;
        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                // remove
                update(nums[i-k], 2);
            }
            // add
            update(nums[i], 1);
            // cout << "right=" << right << endl;
            if (i >= k-1) {
                // get
                res.push_back(right);
            }
        }
        
        return res;
    }
};
