// O(1). maintain two half.
class FrontMiddleBackQueue {
public:
    deque<int> a, b;
    
    FrontMiddleBackQueue() {
        
    }
  
    void a2b(){
        if(a.size() <= b.size()) return;
        b.push_front(a.back());
        a.pop_back();
    }
    
    void b2a(){
        if(b.size() <= a.size()+1) return;
        a.push_back(b.front());
        b.pop_front();
    }
    
    void pushFront(int val) {
        a.push_front(val);
        a2b();
    }
    
    void pushMiddle(int val) {
        a.push_back(val);
        a2b();
    }
    
    void pushBack(int val) {
        b.push_back(val);
        b2a();
    }
    
    int popFront() {
        if(a.empty() && b.empty()) return -1;
        int res;
        if(a.empty()){
            res = b.front();
            b.pop_front();
        }
        else{
            res = a.front();
            a.pop_front();
            b2a();
        }
        return res;
    }
    
    int popMiddle() {
        if(a.empty() && b.empty()) return -1;
        int res;
        if(a.size() == b.size()){
            res = a.back();
            a.pop_back();
        }
        else{
            res = b.front();
            b.pop_front();
        }
        return res;
    }
    
    int popBack() {
        if(a.empty() && b.empty()) return -1;
        int res;
        res = b.back();
        b.pop_back();
        a2b();
        return res;
    }
};

// O(N). use vector, simple
class FrontMiddleBackQueue {
public:
    vector<int> res;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        res.insert(res.begin(), val);
    }
    
    void pushMiddle(int val) {
        res.insert(res.begin()+res.size()/2, val);
    }
    
    void pushBack(int val) {
        res.insert(res.end(), val);
    }
    
    int popFront() {
        if(res.empty()) return -1;
        int x = res[0];
        res.erase(res.begin());
        return x;
    }
    
    int popMiddle() {
        if(res.empty()) return -1;
        int x = res[res.size()/2];
        int id = res.size()/2;
        if(res.size() % 2 == 0) x = res[res.size()/2-1], id--;
        res.erase(res.begin()+id);
        return x;
    }
    
    int popBack() {
        if(res.empty()) return -1;
        int x = res.back();
        res.pop_back();
        return x;
    }
};
