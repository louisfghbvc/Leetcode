//32ms 12.4MB
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(auto &s : emails){
            string em = "";
            for(int i = 0; i < s.size(); ++i){
                if(s[i] == '.') continue;
                if(s[i] == '+'){
                    while(s[i] != '@') i++;
                }
                if(s[i] == '@'){
                    em += s.substr(i); 
                    break;
                }
                em += s[i];
                
            }
            st.insert(em);
        }
        
        return st.size();
    }
};
