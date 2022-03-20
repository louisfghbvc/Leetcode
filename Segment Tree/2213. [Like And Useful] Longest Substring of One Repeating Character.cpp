class Solution {
    
    // can support merge, split
    struct ds{
        map<int, int> mp; // record [l, r]
        multiset<int> st; // record maximum size
        
        int maximum(){
            if(st.empty()) return 0;
            return *st.rbegin();
        }
        
        void erase(int x){
            auto it = prev(mp.upper_bound(x));
            int l = it->first, r = it->second;
            
            mp.erase(l);
            st.erase(st.find(r-l+1));
            if(l == x){    
                if(l+1 <= r)
                    insert(l+1, r);
            }
            else if(r == x){
                if(l <= r-1)
                    insert(l, r-1);
            }
            else{
                if(l <= x-1)
                    insert(l, x-1);
                if(x+1 <= r)
                    insert(x+1, r);
            }
        }
        
        void insert(int x){
            int l = x, r = x;
            auto it = mp.upper_bound(x);

            if(it != mp.begin()){ // append l
                auto pit = prev(it);
                if(pit->second+1 == l){
                    l = pit->first;
                    erase(pit->first, pit->second);
                }  
            }
            if(it != mp.end()){ // append r
                if(r+1 == it->first){
                    r = it->second;
                    erase(it->first, it->second);
                }  
            }
            insert(l, r);
        }
        
        void erase(int l, int r){
            mp.erase(l);
            st.erase(st.find(r-l+1));
        }
        void insert(int l, int r){
            mp[l] = r;
            st.insert(r-l+1);
        }
    };
    
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        // idea: use merge intervals
        // each chars use a interval data struct
        
        vector<int> res;
        
        vector<ds> myDSA(26); // for a-z
        
        // preprocess, record all range -> into dsa
        for(int i = 0, j; i < s.size(); i = j){
            j = i;
            while(j < s.size() && s[j] == s[i]) j++;
            myDSA[s[i] - 'a'].insert(i, j-1);
        }
        
        // each query do online
        for(int i = 0; i < queryIndices.size(); ++i){
            char &origin = s[queryIndices[i]];
            char to = queryCharacters[i];
            myDSA[origin - 'a'].erase(queryIndices[i]);
            myDSA[to - 'a'].insert(queryIndices[i]);
            
            // calculate
            int mx = 0;
            for(int j = 0; j < 26; ++j)
                mx = max(myDSA[j].maximum(), mx);
            res.push_back(mx);
            
            origin = to;
        }
        
        return res;
    }
};
