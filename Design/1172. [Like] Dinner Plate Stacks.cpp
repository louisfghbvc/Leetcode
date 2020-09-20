// The trick is left pointer. this is a important value. make push O(1).
// avg O(1).
// 860ms. 
class DinnerPlates {
public:
    vector<vector<int>> st;
    int cap;
    int left;
    DinnerPlates(int capacity) {
        cap = capacity;
        left = 0;
    }
    
    void push(int val) {
        while(left < st.size() && st[left].size() >= cap) left++;
        if(left == st.size()) st.push_back({val});
        else st[left].push_back(val);
    }
    
    int pop() {
        while(st.size() && st.back().empty()){
            if(st.size()-1 == left) left--;
            st.pop_back();
        }
        if(st.empty()) return -1;
        int res = st.back().back(); st.back().pop_back();
        return res;
    }
    
    int popAtStack(int index) {
        if(st.size() <= index || st[index].empty()) return -1;
        left = min(left, index);
        int res = st[index].back(); st[index].pop_back();
        return res;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
