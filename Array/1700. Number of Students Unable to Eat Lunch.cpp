// Clean version. just cnt one and zero cuz they can move.
// go through b. when not enough break. this can't move.
// O(N).
class Solution {
public:
    int countStudents(vector<int>& a, vector<int>& b) {
        int cnt[2] = {};
        for(int x: a) cnt[x]++;
        int i = 0;
        while(i < b.size()){
            if(cnt[b[i]]) cnt[b[i]]--;
            else break;
            i++;
        }
        return b.size() - i;
    }
};
