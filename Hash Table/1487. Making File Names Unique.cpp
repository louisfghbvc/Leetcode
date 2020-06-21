// Just use Map, not something special
// post fix + make next mp is correct

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> mp;
        for(int i = 0; i < names.size(); ++i){
            if(mp.count(names[i])){
                string tmp = names[i] + "(" + to_string(mp[names[i]]++)+")";
                while(mp.count(tmp)){
                    tmp = names[i] + "(" + to_string(mp[names[i]]++)+")";
                }
                names[i] = tmp;
            }
            mp[names[i]]++;
        }
        return names;
    }
};
