class DataStream {
public:
    
    
    DataStream(int value, int k) : value(value), k(k) {
        
    }
    
    bool consec(int num) {
        if (num == value) cnt++;
        else cnt = 0;
        return cnt >= k; // last k consecutive number is value
    }
    
private:
    int cnt = 0;
    int value, k;
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
