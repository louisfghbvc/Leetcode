// O(N). Boring question.


class Solution {
public:
    int com(vector<int> &v1, vector<int> &v2){
        int i = 0, j = 0;
        while(i < v1.size() || j < v2.size()){
            int x = (i < v1.size()) ? v1[i++] : 0;
            int y = (j < v2.size()) ? v2[j++] : 0;
            if(x > y) return 1;
            else if(x < y) return -1;
        }
        return 0;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        string s = "";
        for(int i = 0; i < version1.size(); ++i){
            if(version1[i] != '.'){
                s += version1[i];
            }
            else{
                v1.push_back(stoi(s));
                s = "";
            }
        }
        v1.push_back(stoi(s));
        s = "";
        
        for(int i = 0; i < version2.size(); ++i){
            if(version2[i] != '.'){
                s += version2[i];
            }
            else{
                v2.push_back(stoi(s));
                s = "";
            }
        }
        v2.push_back(stoi(s));
        
        return com(v1, v2);
    }
};
