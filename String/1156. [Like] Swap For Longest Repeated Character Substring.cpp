// Easy two case. push all repeated. and concate. some edge case.
// if group.size() > 2. so can merge two adjacent and add 1.
// if gap > 1. so left+1 or right+1.
// O(N).
class Solution {
public:
    int maxRepOpt1(string text) {
        text += '$';
        
        int mx = 0;
        for(int i = 0; i < 26; ++i){
            char c = 'a'+i;
            vector<pair<int, int>> tmp;
            
            for(int j = 0, r = 0, l = 0, len = 0; j < text.size(); ++j, ++r){
                if(text[j] == c) len++;
                else{
                    if(len) tmp.push_back({l, r-1});
                    len = 0;
                    l = r+1;
                }
            }
            
            if(tmp.empty()) continue;
            mx = max(mx, tmp[0].second-tmp[0].first+1);
            bool f = (tmp.size() > 2);
            for(int j = 0; j+1 < tmp.size(); ++j){
                auto &[l1, r1] = tmp[j];
                auto &[l2, r2] = tmp[j+1];
                if(r1+2 == l2) mx = max(mx, r1-l1+1 + r2-l2+1 + f);
                else mx = max({mx, r1-l1+2, r2-l2+2});
            }
        }
        return mx;
    }
};

// O(N). sliding window. very Tricky.
class Solution {
public:
    int maxRepOpt1(string text) {
        int mx = 0;
        for(char c = 'a'; c <= 'z'; ++c){
            int i = 0, j = 0, gap = 0, cnt = 0;
            while(i < text.size()){
                if(text[i] == c) cnt++;
                gap += text[i++] != c;
                if(gap > 1) gap -= text[j++] != c;
            }
            mx = max(mx, min(i-j, cnt));
        }
        return mx;
    }
};
