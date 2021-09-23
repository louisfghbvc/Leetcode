// Just two case. proof it by contraction.

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size() == 1) return "";
        
        // two case, try to change to 'a'
        // go first half
        for(int i = 0; i < palindrome.size()/2; ++i){
            if(palindrome[i] == 'a') continue;
            palindrome[i] = 'a';
            return palindrome;
        }
        // try to change 'b'
        // go second half
        for(int i = 0; i < palindrome.size()/2; ++i){
            if(palindrome[i] == 'b') continue;
            palindrome[palindrome.size() - 1 - i] = 'b';
            return palindrome;
        }
        
        return "";
    } 
};
