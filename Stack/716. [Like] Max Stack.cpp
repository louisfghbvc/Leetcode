// use stack, each O(1)
// peekMax O(N).

class MaxStack {
public:
    
    stack<int> st, max_st;
    MaxStack() {
        
    }
    
    void push(int x) {
        int mx = max_st.empty() ? x : max_st.top();
        max_st.push(max(x, mx));
        st.push(x);
    }
    
    int pop() {
        max_st.pop();
        int num = st.top(); st.pop();
        return num;
    }
    
    int top() {
        return st.top();
    }
    
    int peekMax() {
        return max_st.top();
    }
    
    int popMax() {
        int cur = peekMax();
        stack<int> tmp;
        while(top() != cur)
            tmp.push(pop());
        pop();
        while(tmp.size()){
            int x = tmp.top(); tmp.pop();
            push(x);
        }
        return cur;
    }
};

/////////////////////////////////

// use list + map, trick
class MaxStack {
public:
    
    list<int> st;
    map<int, vector<list<int>::iterator>> mp;
    
    MaxStack() {
        
    }
    
    void push(int x) {
        st.insert(st.begin(), x);
        mp[x].push_back(st.begin());
        
    }
    
    int pop() {
        int num = *st.begin();
        mp[num].pop_back();
        if(mp[num].empty()) mp.erase(num);
        st.erase(st.begin());
        return num;
    }
    
    int top() {
        return *st.begin();
    }
    
    int peekMax() {
        return mp.rbegin()->first;
    }
    
    int popMax() {
        int cur = peekMax();
        st.erase(mp[cur].back());
        mp[cur].pop_back();
        if(mp[cur].empty()) mp.erase(cur);
        return cur;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
