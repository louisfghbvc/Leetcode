class MyCalendarTwo {
public:
    map<int, int> fre;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        fre[start]++;
        fre[end]--;
        
        int time = 0;
        for(auto &[k, v]: fre){
            time += v;
            if(time >= 3){
                fre[start]--;
                fre[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
