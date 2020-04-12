class Solution {
public:
    string entityParser(string text) {
        string ans = ""; 
        for(int i = 0; i < text.size(); ++i){
            string t = "";
            if(text[i] == '&'){
                while(i < text.size() && text[i] != ';'){
                    t += text[i++];
                }
                if(i < text.size())
                    t += text[i];
                if(t == "&quot;")
                    t = "\"";
                else if(t == "&apos;")
                    t = "\'";
                else if(t == "&amp;")
                    t = "&";
                else if(t == "&gt;")
                    t = ">";
                else if(t == "&lt;")
                    t = "<";
                else if(t == "&frasl;")
                    t = "/";
            }
            else
                t += text[i];
            
            ans += t;
        }
        return ans;
    }
};
/*
&quot; "\"
"&apos;" "\'"
"&amp;" "&"
"&gt;" ">"
"&lt;" "<"
"&frasl;" "/"
*/
