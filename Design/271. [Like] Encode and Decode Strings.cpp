// this is no error, since we hash first. ascii 256 no error!! tricky

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for(auto &s: strs){
            res += to_string(s.size());
            res += '/';
            res += s;
        }
        cout << res << "\n";
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size()){
            int id = s.find('/', i);
            int num = stoi(s.substr(i, id-i));
            res.push_back(s.substr(id+1, num));
            i = id+1+num;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
