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


// next O(N). do it on the fly
class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        len = combinationLength;
        vis = vector<bool>(s.size());
        for(int i = 0; i < len; ++i)
            vis[i] = 1;
    }
    
    string next() {
        string res = "";
        for(int i = 0; i < s.size(); ++i){
            if(vis[i]) res += s[i];
        }
        
        // find next permutaion
        if(vis[s.size()-1] == 0){ // good case just right shift 1
            // right shift one bit
            for(int i = s.size()-1; i >= 0; i--){
                if(vis[i]){
                    vis[i+1] = 1;
                    vis[i] = 0;
                    break;
                }
            }
        }
        else{
            int oneAtLast = 0;
            int i = s.size()-1;
            while(i >= 0 && vis[i]){
                vis[i] = 0;
                oneAtLast++;
                i--;
            }
            
            if(oneAtLast == len){
                possible = false;
            }
            else{
                // right most 1
                while(i >= 0 && vis[i] == 0){
                    i--;
                }
                
                // put all 1
                vis[i++] = 0;
                vis[i++] = 1;
                
                while(oneAtLast--)
                    vis[i++] = 1;
            }
        }
        
        return res;
    }
    
    bool hasNext() {
        return possible;
    }
private:
    bool possible = true;
    vector<bool> vis;
    string s;
    int len;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
