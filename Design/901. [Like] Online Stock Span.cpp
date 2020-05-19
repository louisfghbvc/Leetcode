// Very Impressive. use stack
// monotone. because max can cover min.
// don't need to record min
class StockSpanner {
public:
    stack<int> arr;
    stack<int> wt;
    StockSpanner() {
    }
    
    int next(int price) {
        int w = 1;
        while(!arr.empty() && arr.top() <= price){
            arr.pop();
            w += wt.top();
            wt.pop();
        }
        arr.push(price);
        wt.push(w);
        return w;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
