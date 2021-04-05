// O(N?). Compare and calculate distance count > 0

class Solution {
public:
    vector<string> ToA(string &s){
        s += ' ';
        vector<string> res;
        string t = "";
        for(char c: s){
            if(c == ' '){
                res.push_back(t);
                t = "";
            }  
            else t += c;
        }
        return res;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> A = ToA(sentence1);
        vector<string> B = ToA(sentence2);
        if(A.size() < B.size()) swap(A, B);
        A.push_back(" ");
        B.push_back(" ");
        vector<int> same;
        same.push_back(-1);
        int j = 0;
        for(int i = 0; i < A.size() && j < B.size(); ++i){
            if(A[i] == B[j]){
                j++;
                same.push_back(i);
            }
        }
        if(j != B.size()) return false;
        int cnt = 0;
        for(int i = 1; i < same.size(); ++i){
            if(same[i] - same[i-1] - 1 > 0) cnt++;
        }
        return cnt <= 1;
    }
};


// Just compare prefix and suffix.
class Solution {
public:
    vector<string> ToA(string &s){
        s += ' ';
        vector<string> res;
        string t = "";
        for(char c: s){
            if(c == ' '){
                res.push_back(t);
                t = "";
            }  
            else t += c;
        }
        return res;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> A = ToA(sentence1);
        vector<string> B = ToA(sentence2);
        int al = 0, ar = A.size()-1, bl = 0, br = B.size()-1;
        while(al <= ar && bl <= br){
            if(A[al] == B[bl]){
                al++;
                bl++;
            }
            else if(A[ar] == B[br]){
                ar--;
                br--;
            }
            else return false;
        }
        return true;
    }
};
