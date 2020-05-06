// O(N), 28ms.
// cnt it because must have one major. 
static int fast = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 1;
}();
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, ans = 0;
        for(const auto &x: nums){
            if(cnt == 0){
                ans = x;
            }
            if(ans != x) cnt--;
            else cnt++;
        }
        return ans;
    }
};
