// Meet in the middle. use set.
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
            auto f = st.lower_bound(goal-tmp);
            if(f != st.end()){
                mn = min(mn, abs(tmp + *f - goal));
            }
            if(f != st.begin()){
                mn = min(mn, abs(tmp + *prev(f) - goal));
            }
        }
        
        return mn;
    }
};


// O(N2^N). use vector more fast.
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        
        int n = nums.size();
        vector<int> st;
        int b = n/2;
        int r = n - b;
        
        int mn = INT_MAX;
        for(int S = 0; S < (1<<b); ++S){
            int tmp = 0;
            for(int j = 0; j < b; ++j) if(S&(1<<j)) tmp += nums[j];
            st.push_back(tmp);
            mn = min(mn, abs(tmp-goal));
        }
        sort(st.begin(), st.end());
        
        for(int S = 0; S < 1<<r; ++S){
            int tmp = 0;
            for(int j = 0; j < r; ++j) if(S&(1<<j)) tmp += nums[j+b];
            
            mn = min(mn, abs(tmp-goal));
            int pos = lower_bound(st.begin(), st.end(), goal-tmp) - st.begin();
            for(int j = pos-1; j <= pos; ++j) {
                if(j >= 0 && j < st.size()) {
                    mn = min(mn, abs(st[j]+tmp - goal));
                }
            }
        }
        
        return mn;
    }
};
