// Meet in the middle.
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        set<int> st;
        int b = n/2;
        
        int mn = INT_MAX;
        for(int S = 0; S < (1<<b); ++S){
            int tmp = 0;
            for(int j = 0; j < b; ++j) if(S&(1<<j)) tmp += nums[j];
            st.insert(tmp);
            mn = min(mn, abs(tmp-goal));
        }
        
        for(int S = 0; S < (1<<(n-b)); ++S){
            int tmp = 0;
            for(int j = b; j < n; ++j) if(S&(1<<(j-b))) tmp += nums[j];
            mn = min(mn, abs(tmp-goal));
            // cout << "cur "<< tmp << "\n";
            auto f = st.lower_bound(goal-tmp);
            if(f != st.end()){
                // cout << "find " << *f << "\n";
                mn = min(mn, abs(tmp + *f - goal));
            }
            if(next(f) != st.end()){
                // cout << "find " << *next(f) << "\n";
                mn = min(mn, abs(tmp + *next(f) - goal));
            }
            if(f != st.begin() && f != st.end()){
                // cout << "find " << *prev(f) << "\n";
                mn = min(mn, abs(tmp + *prev(f) - goal));
            }
        }
        
        return mn;
    }
};
