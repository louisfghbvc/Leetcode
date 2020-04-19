//Just simulate
class Solution {
public:
    string reformat(string s) {
        string a = "", d = "";
        for(auto c: s){
            if(isdigit(c)) d+=c;
            else a+=c;
        }
        string ans = "";
        int as = a.size(), ds = d.size();
        if(abs(as - ds) <= 1){
            if(as == ds){
                for(int i = 0; i < as; ++i){
                    ans += a[i];
                    ans += d[i];
                }
                    
            }
            else{
                if(as < ds) swap(a, d);
                ans = a[0];
                for(int i = 1; i < a.size(); ++i){
                    ans += d[i-1];
                    ans += a[i];
                }  
            }
        }
        
        return ans;
    }
};1417. Reformat The String
