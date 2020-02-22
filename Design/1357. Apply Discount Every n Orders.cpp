class Cashier {
private:
    int cnt, dc, n;
    vector<int> prices;
    unordered_map<int, int> mp;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        cnt = 0;
        dc = discount;
        this->n = n;
        for(int i = 0; i < products.size(); ++i){
            mp[products[i]] = i;
        }
        this->prices = prices;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double res = 0.0;
        for(int i = 0; i < amount.size(); ++i){
            res += amount[i] * prices[mp[product[i]]];
        }
        ++cnt;
        if(cnt % n == 0){
            res = res - (res * dc) / 100.0;
        }
        return res;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
