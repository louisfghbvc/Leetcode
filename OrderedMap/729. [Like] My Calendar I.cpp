// O(NlogN). always check closest possible enough.

class MyCalendar {
public:
    map<int, int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto p = mp.upper_bound(start);
        if(p != mp.end()){
            if(end > p->first) return false;
        }
        if(p != mp.begin()){
            if(start < prev(p)->second) return false;
        }
        mp[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
