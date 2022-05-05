// follow up, only use one queue
// O(N) in push, other O(1)

class MyStack {
public:
    MyStack() {
        
    }
    
    // [1, 2, 3, 4]
    // 3 2 1 4
    void push(int x) {
        q.push(x);
        // push all previous thing to last
        for (int i = q.size()-1; i > 0; --i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
    
private:
    queue<int> q; // only use one queue
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
