// Simple call stl libary.
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if(!next_permutation(s.begin(), s.end())) return -1;
        long v = stoll(s);
        return v >= INT_MAX ? -1 : v;
    }
};

// next_permutation done by self. O(N).
// check the increasing pair. and from right to begin
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if(!next_p(s)) return -1;
        long v = stoll(s);
        return v >= INT_MAX ? -1 : v;
    }
    
    bool next_p(string &s){
        int i = s.size()-1;
        for(; i >= 1 && s[i-1] >= s[i]; --i);
        if(i == 0) return false;
        
        int j = s.size()-1;
        for(; s[i-1] >= s[j]; --j);
        swap(s[i-1], s[j]);
        
        reverse(s.begin() + i, s.end());
        
        return true;
    }
    
};
