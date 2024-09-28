// think the fix array, just maintain a two pointer

class MyCircularDeque {
public:

    MyCircularDeque(int k) {
        arr.resize(k);        
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        size++;
        arr[start] = value;
        start--;
        if (start < 0) start = arr.size()-1;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        size++;
        arr[end] = value;
        end++;
        if (end == arr.size()) end = 0;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        size--;
        start++;
        if (start == arr.size()) start = 0;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        size--;
        end--;
        if (end < 0) end = arr.size()-1;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return arr[(start+1)%arr.size()];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return arr[(end-1+arr.size())%arr.size()];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == arr.size();
    }

private:
    vector<int> arr;
    int start = 0, end = 1;
    int size = 0;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
