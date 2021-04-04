// Tricky use mod. O(1)

class MyCircularQueue {
public:
    vector<int> arr;
    int front = 0, rear = -1, len = 0;
    MyCircularQueue(int k) {
        arr.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        rear = (rear+1) % arr.size();
        arr[rear] = value;
        len++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front+1) % arr.size();
        len--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return len == 0;
    }
    
    bool isFull() {
        return len == arr.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
