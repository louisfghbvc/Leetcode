// O(N). Straight
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool first = true, all = true, allc = true;
        for(int i = 0; i < word.size(); ++i){
            if(islower(word[i])){
                all = false;
                if(!i) first = false;
            }
            else {
                if(i) first = false;
                allc = false;
            }
        }
        if(all || first || allc) return true;
        return false;
    }
};

// O(N). Clean
class Solution {
public:
    bool detectCapitalUse(string word) {
        int C = 0;
        for(auto &c: word) if(isupper(c)) C++;
        return C == word.size() || C == 1 && isupper(word[0]) || C == 0;
    }
};

// Python op.
