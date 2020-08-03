// Just Reverse string but only reverse Vowels. O(N).

class Solution {
public:
    bool isV(char &c){
        return c == 'a' || c == 'e' || c == 'i'|| c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I'|| c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        for(int i = 0, j = s.size()-1; i < j; i++, j--){
            while(!isV(s[i]) && i < j) i++;
            while(!isV(s[j]) && i < j) j--;
            if(i < j) swap(s[i], s[j]);
        }
        return s;
    }
};
