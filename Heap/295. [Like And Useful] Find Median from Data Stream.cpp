class MedianFinder {
public:
    /** initialize your data structure here. */
    
    multiset<int> s1, s2;
    MedianFinder() {
        
    }
    
    void balance(){
        if(s1.size() > s2.size()){
            int x = *s1.rbegin();
            s2.insert(x);
            s1.erase(s1.find(x));
        }
        else if(s1.size()+1 < s2.size()){
            int x = *s2.begin();
            s1.insert(x);
            s2.erase(s2.find(x));
        }
    }
    
    void addNum(int num) {
        if(s1.size() && num <= *s1.rbegin()){
            s1.insert(num);
        }
        else s2.insert(num);
        balance();
    }
    
    double findMedian() {
        if(s1.size() == s2.size())
            return (*s1.rbegin() + *s2.begin()) * 1.0 / 2.0;
        return *s2.begin();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
