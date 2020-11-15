// reading problem statement... take a lots of time.
// stupid implement.

class OrderedStream {
public:
    int ptr;
    vector<string> res;
    
    OrderedStream(int n) {
        ptr = 0;
        res = vector<string>(n);
    }
    
    vector<string> insert(int id, string value) {
        id--;
        res[id] = value;
        if(id == ptr){
            vector<string> tmp;
            while(ptr < res.size() && res[ptr].size()) tmp.push_back(res[ptr++]);
            return tmp;
        }
        return {};
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
