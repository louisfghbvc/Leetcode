// Sort it, and use int trie. 

class Solution {
public:
    struct node{
        node* next[2];
        node(){
            memset(next, 0, sizeof next);
        }
    };
    node *root;
    
    void add(int x){
        node *cur = root;
        for(int i = 30; i >= 0; --i){
            bool bit = x&(1<<i);
            if(!cur->next[bit]){
                cur->next[bit] = new node();
            }
            cur = cur->next[bit];
        }
    }
    
    int search(int x){
        node* tmp = root;
        int res = 0;
        int i;
        for(i = 30; i >= 0 && tmp; --i){
            bool cur = x&(1<<i);
            if(tmp->next[!cur]){
                res |= (1<<i);
                tmp = tmp->next[!cur];
            }
            else
                tmp = tmp->next[cur];
        }
        if(i >= 0) return -1;
        return res;
    }
    
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& qy) {
        root = new node();
        sort(nums.begin(), nums.end());
        
        int n = qy.size();
        for(int i = 0; i < n; ++i)
            qy[i].push_back(i);
        
        sort(qy.begin(), qy.end(), [](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });
        
        vector<int> res(n);
        int i = 0;
        for(auto&q: qy){
            int x = q[0], m = q[1], id = q[2];
            while(i < nums.size()){
                if(nums[i] <= m) add(nums[i++]);
                else break;
            }
            res[id] = search(x);
        }
        
        return res;
    }
};
