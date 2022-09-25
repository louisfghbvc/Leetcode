class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0); // assign from 0-n-1
        
        sort(order.begin(), order.end(), [&](int i, int j) {
           return heights[i] > heights[j]; 
        });
        
        vector<string> res;
        for (int i: order)
            res.push_back(names[i]);
        return res;
    }
};
