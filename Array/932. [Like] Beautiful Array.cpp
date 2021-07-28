// Postorder.
// Hard to think.
// D&C
// O(NlogN)
class Solution {
public:
    vector<int> beautifulArray(int n) {
        if(n == 1) return {1};
        // seperate to two part, odd part, even part
        // {1, 3, 5, 7}, {2, 4, 6, 8}
        // but {1, 3, 5, 7} still conflict. observe that {3, 7, 1, 5} -> {2, 4, 1, 3}, do it recursive
        //      1  2  3  4    
        vector<int> odd = beautifulArray((n + 1)/ 2);
        vector<int> even = beautifulArray(n / 2);
        vector<int> res;
        for(auto &e: odd)
            res.push_back(2 * e - 1);
        for(auto &e: even)
            res.push_back(2 * e);
        return res;
    }
};
