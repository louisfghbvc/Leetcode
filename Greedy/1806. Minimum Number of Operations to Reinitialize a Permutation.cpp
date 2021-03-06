// O(N^2) Brute Force. assume the change no more than n.. since cycle.

class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) arr[i] = i;
        vector<int> tmp = arr;
        int op = 0;
        do{
            vector<int> nxt = tmp;
            for(int i = 0; i < n; ++i){
                if(i % 2 == 0) nxt[i] = tmp[i/2];
                else nxt[i] = tmp[n/2 + (i-1)/2];
            }
            tmp = nxt;
            op++;
        }while(tmp != arr);
        return op;
    }
};


// O(N). Think as graph, only move one vertex.
class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> graph(n);
        for(int i = 0; i < n; ++i)
            graph[i] = i%2 ? n/2 + (i-1)/2 : i/2;
        int cur = graph[1], ans = 1;
        while(cur != 1){
            cur = graph[cur];
            ans++;
        }
        return ans;
    }
};
