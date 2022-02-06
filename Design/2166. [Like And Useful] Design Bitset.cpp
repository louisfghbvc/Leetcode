// each O(1), use flag.

class Bitset {
private:
    string s;
    bool f; // flip or not
    int cnt; // number of one
    
public:
    Bitset(int size) {
        s.assign(size, '0');
        f = false;
        cnt = 0;
    }
    
    void fix(int idx) {
        if(s[idx] == ('0' ^ f)){
            s[idx] = '1' ^ f;
            cnt++;
        }
    }
    
    void unfix(int idx) {
        if(s[idx] == ('1' ^ f)){
            s[idx] = '0' ^ f;
            cnt--;
        }
    }
    
    void flip() {
        cnt = s.size() - cnt;
        f = !f;
    }
    
    bool all() {
        return cnt == s.size();
    }
    
    bool one() {
        return cnt > 0;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string res = "";
        for(int i = 0; i < s.size(); ++i)
            res.push_back(s[i] ^ f);
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
