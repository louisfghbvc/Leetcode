// hash the fre stack, each fre has a stack so that the pop will not change data structure.
// O(logN).
class FreqStack {
public:
    map<int, stack<int>> mostSt;
    unordered_map<int, int> fre;
    FreqStack() {
        
    }
    
    void push(int x) {
        mostSt[++fre[x]].push(x);
    }
    
    int pop() {
        auto &[key, st] = *mostSt.rbegin();
        int x = st.top(); st.pop();
        fre[x]--;
        if(st.empty()) mostSt.erase(key);
        return x;
    }
};

// O(1). just use vector as stack map. maintain a pointer.
class FreqStack {
public:
    vector<stack<int>> mostSt;
    unordered_map<int, int> fre;
    int pos;
    FreqStack() {
        pos = 0;
    }
    
    void push(int x) {
        int opp = ++fre[x];
        if(opp >= mostSt.size()) mostSt.push_back(stack<int>());
        mostSt[opp-1].push(x);
        pos = max(pos, opp-1);
    }
    
    int pop() {
        int x = mostSt[pos].top(); mostSt[pos].pop();
        --fre[x];
        if(mostSt[pos].empty()) pos--;
        return x;
    }
};

// O(1). easy code same as solution2, lee215 method.
// Space is low
class FreqStack {
public:
    unordered_map<int, stack<int>> mostSt;
    unordered_map<int, int> fre;
    int pos;
    FreqStack() {
        pos = 0;
    }
    
    void push(int x) {
        int opp = ++fre[x];
        mostSt[opp].push(x);
        pos = max(pos, opp);
    }
    
    int pop() {
        int x = mostSt[pos].top(); mostSt[pos].pop();
        --fre[x];
        if(mostSt[pos].empty()) pos--;
        return x;
    }
};
