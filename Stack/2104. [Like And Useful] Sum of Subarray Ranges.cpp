// O(N) approach, two pass
// first pass is sum of min-array
// second pass is sum of max-array
// ans = sum_max - sum_min

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // first calculate the sum of min array
        long sum_min = 0, sum_max = 0;

        {
            long sum = 0;
            stack<pair<int, int>> st; // element, cnt
            for(int x: nums){
                int cnt = 1;
                while(st.size() && st.top().first >= x){
                    cnt += st.top().second;
                    sum -= (long)st.top().first * st.top().second;
                    st.pop();
                }
                sum += (long)cnt * x;
                st.push({x, cnt});
                sum_min += sum;
            }
        } 
        {  // just reverse
            long sum = 0;
            stack<pair<int, int>> st; // element, cnt
            for(int x: nums){
                int cnt = 1;
                while(st.size() && st.top().first <= x){
                    cnt += st.top().second;
                    sum -= (long)st.top().first * st.top().second;
                    st.pop();
                }
                sum += (long)cnt * x;
                st.push({x, cnt});
                sum_max += sum;
            }
        } 
        
        return sum_max - sum_min;
    }
};
