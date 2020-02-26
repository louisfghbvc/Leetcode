//0ms 8.9MB
class Solution {
public:
    char toLow(char c){
        if(c >= 'A' && c <= 'Z') 
            return c - 'A' + 'a';
        return c;
    }
    string wordBegin(char c){
        switch(toLow(c)){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return "ma";
                break;
            default:
                break; 
        }
        return string(1, c) + "ma";
    }
    string toGoatLatin(string S) {
        string res = "";
        for(int i = 0, wcnt = 1; i < S.size(); ++i){
            if(wcnt > 1)
                res += ' ';
            int j = i;
            bool f = true;
            for(; j < S.size() && S[j] != ' '; ++j){
                if(f){
                    if(wordBegin(S[j]) == "ma")
                        res += S[j];  
                    f = false;
                    continue;
                }
                res += S[j];
            }
            res += wordBegin(S[i]);
            for(int k = 0; k < wcnt; ++k){
                res += 'a';
            }
            i = j;
            wcnt++;
        }
        return res;
    }
};

//4ms 9.2MB clean code
class Solution {
public:
    string toGoatLatin(string S) {
        stringstream iss(S), oss;
        string vowel("aeiouAEIOU"), word, a;
        while(iss >> word){
            a.push_back('a');
            if(vowel.find_first_of(word[0]) != -1)
                oss << " " << word + "ma" + a;
            else
                oss << " " << word.substr(1) << word[0] << "ma" + a;
        }
        return oss.str().substr(1);
    }
};
