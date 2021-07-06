// O(NlogN). depends on sort. Remove biggest

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> fre;
        for(int x: arr) fre[x]++;
        
        vector<int> tot_fre;
        for(auto &[k, f]: fre) tot_fre.push_back(f);
        
        sort(tot_fre.begin(), tot_fre.end(), greater<>()); // this can use bucket sort
        
        int target = arr.size() / 2;
        for(int i = 0; i < tot_fre.size(); ++i){
            target -= tot_fre[i];
            if(target <= 0) return i+1;
        }
        
        return tot_fre.size();
    }
};
