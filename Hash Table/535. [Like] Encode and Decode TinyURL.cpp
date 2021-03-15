// Base62.

const string base62c = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

class Solution {
private:
    int id = 0;
    unordered_map<string, string> url;
public:
    string ToBase62(int base10) {
        string base62;
        if(base10 < 62)
            return string(1, base62c[base10]);
        
        while(base10)
            base62 += base62c[base10 % 62], base10 /= 62;

        reverse(base62.begin(), base62.end());
        return base62;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string sid = ToBase62(id++);
        url[sid] = longUrl;
        return sid;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return url[shortUrl];
    }
};
