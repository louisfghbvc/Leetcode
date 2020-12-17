// just like BF. and make it two sum able.
// so like search method, divide into two. and enum other two. check if is in the map.
// O(N^2).

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int cnt = 0;
        unordered_map<int, int> mp;
        for(int a: A)
            for(int b: B)
                mp[a+b]++;
                
        for(int c: C)
            for(int d: D)
                cnt += mp[-(c+d)];
        return cnt;
    }
};
