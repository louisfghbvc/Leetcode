// Hard to think... Wow.
// Stack put the maximum. decreasing. 
// 132 same as 231 reverse.
// so from backward.
// say p2 is minimum.
// if a num[i] > p2. find it 231.
// when nums[i] > st.top(). say the biggest is gg. so biggest go to p2. so that maintain the order.
// need example thinking.
// O(N).

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int p2 = INT_MIN;
        for(int i = n-1; i >= 0; --i){
            if(nums[i] < p2) return true;
            while(st.size() && st.top() < nums[i]){
                p2 = st.top(); st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};


// Easy O(N^2). just monotonous
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int mn = nums[0];
        for(int j = 1; j < n; ++j){
            for(int k = j+1; k < n; ++k){
                if(mn < nums[k] && nums[k] < nums[j])
                    return true;
            }
            mn = min(nums[j], mn);
        }
        return false;
    }
};
