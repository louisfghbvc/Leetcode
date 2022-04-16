class ATM {
public:
    
    // simulate the process
    
    ATM() {
        cnt.resize(5);
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i)
            cnt[i] += banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        vector<int> res(5);
        
        for (int i = 4; amount && i >= 0; --i) {
            if (!cnt[i]) continue;
            if (amount >= dollars[i]) { // must use
                int need = min(amount / dollars[i], cnt[i]);
                res[i] += need;
                amount -= need * dollars[i];
            }
        }
        
        if (amount) return {-1};
        
        for (int i = 0; i < 5; ++i)
            cnt[i] -= res[i];
        
        return res;
    }
    
private:
    vector<long> cnt;
    vector<long> dollars = {20, 50, 100, 200, 500};
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
