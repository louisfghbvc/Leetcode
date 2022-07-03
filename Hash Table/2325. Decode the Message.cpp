class Solution {
public:
    string decodeMessage(string key, string message) {
        // mapping
        
        unordered_map<char, char> mp;
        int id = 0;
        for (char c: key) {
            if (!mp.count(c) && c != ' ')
                mp[c] = 'a' + id++;
        }
        
        for (char &c: message) if (c != ' ')
            c = mp[c];
        return message;
    }
};
