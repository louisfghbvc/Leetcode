// Like Uva 514 Rails.
// keep now. and while(now < target). push "push", "pop"
// now == target push "push".
// O(n).

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int now = 1;
        vector<string> ans;
        for(int i = 0; i < target.size(); ++i){
            if(now == target[i]) now++, ans.push_back("Push");
            else if(now < target[i]){
                while(now < target[i]){
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    now++;
                }
                now++;
                ans.push_back("Push");
            }
        }
        return ans;
    }
};
