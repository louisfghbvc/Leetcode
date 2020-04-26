// Straight Forward. O(N)
// key point i+j is same group
// 336ms 77.7MB.
static int p = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int r = nums.size(), ml = 0;;
        vector<int> ans;
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < nums[i].size(); ++j){
                ml = max(i+j, ml);
            }
        }
        vector<int> lt[ml+1];
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < nums[i].size(); ++j){
                lt[i+j].push_back(nums[i][j]);
            }
        }
        for(int i = 0; i < ml+1; ++i){
            for(int j = lt[i].size()-1; j >= 0; --j){
                ans.push_back(lt[i][j]);
            }
        }
        return ans;
    }
};
