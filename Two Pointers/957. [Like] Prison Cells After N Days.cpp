// Floyd cycle detect.
// Not use hash table

class Solution {
public:
    vector<int> func(vector<int> &cur){
        vector<int> nxt = cur;
        nxt[0] = nxt[7] = 0;
        for(int i = 1; i < 7; i++){
            nxt[i] = (cur[i-1]==cur[i+1]);
        }
        return nxt;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> slow = cells, fast = cells;
        do{
            slow = func(slow);
            fast = func(fast);
            fast = func(fast);
        }while(slow != fast);
        
        slow = cells;
        int f = 0;
        while(slow != fast){
            slow = func(slow);
            fast = func(fast);
            f++;
        }
        if(N <= f){
            slow = cells;
            for(int i = 0; i < N; ++i) slow = func(slow);
            return slow;
        }
        N -= f;
        int cyc = 0;
        do{
            fast = func(fast);
            cyc++;
        }while(slow != fast);
        N %= cyc;
        for(int i = 0; i < N; ++i) slow = func(slow);
        return slow;
    }
};
