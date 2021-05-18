// Go through string.

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp; // content to file name list
        
        for(auto &s: paths){
            
            // find root
            string root = "";
            int i = 0;
            for(; s[i] != ' '; ++i) root += s[i];
            
            // find files
            string file = "", content = "";
            bool startC = false;
            for(; i < s.size(); ++i){
                if(s[i] == ' ') continue;
                if(s[i] == '(') startC = true;
                else if(s[i] == ')'){
                    mp[content].push_back(root + "/" + file);
                    content = file = "";
                    startC = false;
                }
                else{
                    if(startC) content += s[i];
                    else file += s[i];
                }
            }
        }
        
        // dump to ouput
        vector<vector<string>> res;
        for(auto &[content, filelist]: mp)
            if(filelist.size() > 1)
                res.emplace_back(filelist);
        
        return res;
    }
};
