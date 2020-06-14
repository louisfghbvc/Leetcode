// Fisrt map it, second. input array.
// then sort, finally, traversal array.
// ans = mp.size();
// when k < arr[i]. return ans
//O(NlogN)

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto& v: arr){
            mp[v]++;
        }
        vector<int> tmp;
        for(auto&m : mp){
            tmp.push_back(m.second);
        }
        int ans = mp.size();
        sort(tmp.begin(), tmp.end());
        for(auto&x: tmp){
            if(k == 0 || k < x) return ans;
            k -= x;
            ans--;
        }
        return ans;
    }
};
