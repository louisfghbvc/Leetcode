//stl amazing.
class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> st(arr.begin(), arr.end());
        int res = 0;
        for(const auto &x : arr)
            if(st.count(x+1)) res++;
        return res;
    }
};
