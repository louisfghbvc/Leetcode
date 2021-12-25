// just do as problem saying
// O(N)

class Solution {
public:

    string justification(vector<string> &w, int len, int width){
        if(w.size() == 1) return w[0] + string(width-w[0].size(), ' ');
        
        string res = "";
        int each_space = (width - len) / (w.size()-1);
        int remain = (width - len) % (w.size()-1);
        
        for(int i = 0; i < remain; ++i){
            res += w[i];
            res += string(each_space+1, ' ');
        }
        
        for(int i = remain; i < w.size(); ++i){
            res += w[i];
            if(i+1 != w.size())
                res += string(each_space, ' ');
        }
        
        return res;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        
        // try to add greedy as possible
        // if can not add, try next line
        int cur_line = 0;
        int space = 0;
        vector<string> line;
        for(int i = 0; i < words.size(); ++i){
            if(cur_line + words[i].size() + space <= maxWidth){
                cur_line += words[i].size();
                line.push_back(words[i]);
                space++;
            }
            else{
                res.push_back(justification(line, cur_line, maxWidth));
                space = 1;
                cur_line = words[i].size();
                line = {words[i]};
            }
        }
        
        // lastline
        string lastline = "";
        for(int i = 0; i < line.size(); ++i){
            lastline += line[i];
            if(i+1 != line.size())
                lastline += ' ';
            else
                lastline += string(maxWidth - lastline.size(), ' ');
        }
        
        if(lastline.size()) res.push_back(lastline);
        return res;
    }
};
