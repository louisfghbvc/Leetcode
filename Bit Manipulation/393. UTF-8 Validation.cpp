// Clean code. case sensitive...
// O(N).

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int nb = 0;
        for(int x: data){
            if(!nb){
                if((x>>5) == 6) nb = 1;
                else if((x>>4) == 0b1110) nb = 2;
                else if((x>>3) == 0b11110) nb = 3;
                else if((x>>7)) return false;
            }
            else{
                if((x>>6) != 2) return false;
                nb--;
            }
        }
        return nb == 0;
    }
};

// ugly cnt bit.

class Solution {
public:
    int cnt(int x){
        int res = 0;
        for(int i = 7; i >= 0 && (1<<i)&x; --i) res++;
        return res;
    }
    bool validUtf8(vector<int>& data) {
        int nb = 0;
        for(int i = 0; i < data.size(); ++i){
            int x = data[i];
            int b = cnt(x);
            if(b > data.size()-i || b > 4) return false;
            if(b == 0){
                if(nb) return false;
            }
            else{
                if(!nb) {
                    if(b == 1) return false;
                    nb = b;
                }
                else if(b != 1) return false;
                nb--;
            }
        }
        return true;
    }
};
