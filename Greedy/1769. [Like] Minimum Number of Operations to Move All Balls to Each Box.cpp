// Greedy Prefix. O(N). like dp.
// ops means move cnt to currnet position. same as right to left.

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);

        for(int i = 0, cnt = 0, ops = 0; i < n; ++i){
            res[i] += ops;
            cnt += boxes[i] == '1';
            ops += cnt;
        }
        
        for(int i = n-1, cnt = 0, ops = 0; i >= 0; --i){
            res[i] += ops;
            cnt += boxes[i] == '1';
            ops += cnt;
        }
        
        return res;
    }
};

// Brute Force. O(N^2)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);
        
        vector<int> idx;
        for(int i = 0; i < n; ++i){
            if(boxes[i] == '1'){
                idx.push_back(i);
            }
        }
        
        for(int i = 0; i < n; ++i){
            int cnt = 0;
            for(int id: idx){
                if(i == id) continue;
                cnt += abs(i-id);
            }
            res[i] = cnt;
        }
        
        return res;
    }
};
