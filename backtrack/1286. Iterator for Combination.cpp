// pre-calculate all case.
// and just straight forward.
// O(2^N).
class CombinationIterator {
public:
    vector<string> arr;
    int it = 0;
    CombinationIterator(string str, int len) {
        function <void(string, int)> dfs;
        dfs = [&](string s, int st){
            if(s.size() == len){
                arr.push_back(s);
                return;
            }
            for(int i = st; i < str.size(); ++i){
                dfs(s+str[i], i+1);
            }
        };
        dfs("", 0);
    }
    
    string next() {
        return arr[it++];
    }
    
    bool hasNext() {
        return it < arr.size();
    }
};
