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


// use custom string iter
class Iter{
public:
    Iter(string &s): s(s), i(0) {}
    bool hasNext(){
        return i < s.size();    
    }
    int get(){
        int tmp = 0;
        while(i < s.size() && s[i] != '.')
            tmp = tmp * 10 + s[i++] - '0';
        i++;
        return tmp;
    }
    
private:
    string s;
    int i;
};

class Solution {
public:
    int compareVersion(string version1, string version2) {
        // revisions constraint
        
        Iter a(version1), b(version2);
        
        while(a.hasNext() || b.hasNext()){
            int va = 0, vb = 0;
            if(a.hasNext())
                va = a.get();
            if(b.hasNext())
                vb = b.get();
            if(va != vb)
                return (va < vb) ? -1 : 1;
        }
        
        return 0;
    }
};

// use stringstream, concise
class Solution {
public:
    int compareVersion(string version1, string version2) {
        // use stringstream

        for(auto &c: version1) if(c == '.') c = ' ';
        for(auto &c: version2) if(c == '.') c = ' ';
        
        istringstream s1(version1), s2(version2);
        while(1){
            int number1, number2;
            if(!(s1 >> number1)) number1 = 0;
            if(!(s2 >> number2)) number2 = 0;
            if(!s1 && !s2) return 0;
            if(number1 < number2) return -1;
            if(number1 > number2) return 1;
        }
        return 0;
    }
};
