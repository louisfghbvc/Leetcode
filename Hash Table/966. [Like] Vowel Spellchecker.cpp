// understand the problem... and just  1 set + 2 map

class Solution {
public:
    set<char> vowel = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string tolow(string s){
        string t = "";
        for(char &c: s)
            t += tolower(c);
        return t;
    }
    string tovowel(string s){
        string t = "";
        for(char &c: s)
            t += (vowel.count(c) ? '#' : c);
        return t;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> bag(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap;
        unordered_map<string, string> cap_vowel;
        for(auto &w: wordlist){
            string lower = tolow(w);
            string devowel = tovowel(lower);
            cap.insert({lower, w});
            cap_vowel.insert({devowel, w});
        }
        
        vector<string> res;
        for(auto &s: queries){
            string t = tolow(s);
            string dev = tovowel(t);
            if(bag.count(s)){
                res.push_back(s);
            }
            else if(cap.count(t)){
                res.push_back(cap[t]);
            }
            else if(cap_vowel.count(dev)){
                res.push_back(cap_vowel[dev]);
            }
            else res.push_back("");
        }
        
        return res;
    }
};
