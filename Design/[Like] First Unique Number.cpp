// Use queue + map.
// Very sample, like cache. can also use linkedlist solve it. same idea. 
// 344ms 80.8MB
static int fast = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 1;
}();
class FirstUnique {
public:
    queue<int> q;
    unordered_map<int, int> mp;
    
    FirstUnique(vector<int>& nums) {
        for(const auto &v: nums){
            q.push(v);
            mp[v]++;
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() && mp[q.front()] > 1){
            q.pop();
        }
        return q.empty() ? -1 : q.front();
    }
    
    void add(int value) {
        q.push(value);
        mp[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
