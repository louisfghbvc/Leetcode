class Solution {
public:
    int distinctIntegers(int n) {
        // idea: simulate it
        
        unordered_set<int> arr = {n};
        
        bool ch = true;
        while (ch) {
            ch = false;
            int prev = arr.size();
            for (int x: arr) {
                for (int i = 1; i <= n; ++i) {
                    if (x % i == 1) arr.insert(i);
                }
            }
            if (arr.size() != prev) ch = true;
        }
        
        return arr.size();
    }
};



// Solution2, Observe
