// can use regex. more clean.
class Solution {
public:
    bool IPv4(string s){
        if(s.size() == 0) return 0;
        vector<string> arr;
        string t = "";
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '.'){
                arr.push_back(t);
                t = "";
            } else{
                t += s[i];
            }
        }
        arr.push_back(t);
        if(arr.size() != 4) return 0;
        for(auto &st : arr){
            if(!st.size() || (st.size() > 1 && st[0] == '0') || st.size() > 4) return 0;
            int num = 0;
            for(auto &c: st){
                if(!isdigit(c)) return 0;
                num = num*10 + (c-'0');
            }
            if(num > 255) return 0;
        }
        return 1;
    }
    bool IPv6(string s){
        if(s.size() == 0) return 0;
        vector<string> arr;
        string t = "";
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ':'){
                arr.push_back(t);
                t = "";
            } else{
                t += s[i];
            }
        }
        arr.push_back(t);
        if(arr.size() != 8) return 0;
        for(auto &st : arr){
            if(st.size() > 4 || !st.size()) return 0;
            for(auto &c: st){
                c = tolower(c);
                if(isdigit(c)) continue;
                if(c > 'z' || c < 'a') return 0;
                if(c > 'f') return 0;
            }
        }
        return 1;
    }
    string validIPAddress(string IP) {
        if(IPv4(IP)) return "IPv4";
        if(IPv6(IP)) return "IPv6";
        return "Neither";
    }
};

// Regex. very slow.
class Solution {
public:
    string validIPAddress(string IP) {
        regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        regex ipv6("(([0-9a-fA-F]){1,4}\\:){7}([0-9a-fA-F]){1,4}");
        if(regex_match(IP, ipv4)) return "IPv4";
        if(regex_match(IP, ipv6)) return "IPv6";
        return "Neither";
    }
};
