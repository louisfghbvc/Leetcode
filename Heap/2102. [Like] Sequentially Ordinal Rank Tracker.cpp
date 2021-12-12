// similar to maintain two heap
// just balance like dynamic medium.
// O(logk)
class SORTracker {
public:
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        right.insert({-score, name});
        balance();
    }
    
    void balance(){
        if(right.empty()) return;
        left.insert(*right.begin()); right.erase(right.begin());
        if(left.size() > k){
            right.insert(*left.rbegin());
            left.erase(*left.rbegin());
        }
    }
    
    string get() {
        string res = left.rbegin()->second;
        k++;
        balance();
        return res;
    }
private:
    set<pair<int, string>> left, right;
    int k = 1;
};


// moving pointer! trick
class SORTracker {
public:
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        auto it1 = st.insert({-score, name}).first;
        if(it == st.end() || *it1 < *it)
            --it;
    }
    
    string get() {
        return (it++)->second;
    }
    
private:
    set<pair<int, string>> st;
    set<pair<int, string>>::iterator it = st.end(); // ith
};
