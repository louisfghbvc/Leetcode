//STL rotate. add all operation. rotate.
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int cnt = 0;
        for(auto st: shift){
            if(st[0]) cnt -= st[1];
            else cnt += st[1];
        }
        cnt %= (int)s.size();
        if(cnt > 0){
            rotate(s.begin(), s.begin()+cnt, s.end());
        }
        else{
            rotate(s.rbegin(), s.rbegin()-cnt, s.rend());
        }
        return s;
    }
};
//Brute Force. 
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        for(auto st : shift){
            if(st[0]){
                for(int i = 0; i < st[1]; ++i){
                    for(int j = s.size()-1; j >= 1; --j){
                        swap(s[j], s[j-1]);
                    }
                }
            }   
            else{
                for(int i = 0; i < st[1]; ++i){
                    for(int j = 0; j < s.size() - 1; ++j){
                        swap(s[j], s[j+1]);
                    }
                }
            }
        }
        
        return s;
    }
};
