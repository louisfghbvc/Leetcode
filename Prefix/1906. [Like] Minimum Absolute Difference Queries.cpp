// OK... Prefix sum O(100N). fastest.

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> pre(nums.size()+1, vector<int>(101, 0));
        
        vector<int> cnt(101);
        for(int i = 0; i < nums.size(); ++i){
            cnt[nums[i]]++;
            pre[i+1] = cnt;
        }
        
        vector<int> res;
        for(auto q: queries){
            int l = q[0], r = q[1];
            int tmp = 1e5;
            int p = -1;
            for(int i = 1; i <= 100; ++i){
                if(pre[r+1][i] - pre[l][i]){
                    if(p != -1)
                        tmp = min(tmp, i-p);
                    p = i;
                }
            }
            if(tmp == 1e5) tmp = -1;
            res.push_back(tmp);
        }
        
        return res;
    }
};

// Contest code. extand segment. AC in 12:00 QQ. a little slow
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<vector<int>> arr;
        for(int i = 0; i < queries.size(); ++i){
            arr.push_back({queries[i][0], queries[i][1], i});
        }
        
        sort(arr.begin(), arr.end());
        
        vector<int> res(queries.size());
        
        vector<int> fre(105);
        auto gg = [&](){
            int res = 1e5;
            int p = -1;
            for(int i = 1; i <= 100; ++i){
                if(fre[i]){
                    if(p != -1)
                        res = min(i - p, res);
                    p = i;
                }
            }
            return res;
        };
        
        
        int cl = -1, cr = -1;
        for(auto &q: arr){
            int l = q[0], r = q[1], id = q[2];
            if(cl == -1){
                for(int i = l; i <= r; ++i){
                    fre[nums[i]]++;
                }
                cl = l, cr = r;
            }
            else{
                if(l != cl){
                    for(int i = cl; i < l; ++i){
                        fre[nums[i]]--;
                    }
                    for(int i = l; i < cl; ++i) fre[nums[i]]++;
                }
                if(r != cr){
                    for(int i = cr+1; i <= r; ++i){
                        fre[nums[i]]++;
                    }
                    for(int i = r+1; i <= cr; ++i) fre[nums[i]]--;
                }
                cl = l, cr = r;
            }
            
            
            int tmp = gg();
            if(tmp == 1e5) tmp = -1;
            res[id] = tmp;
        }
        
        return res;
    }
};

// Binary Search. O(100q * logN). a little slow

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> fre(101);
        
        for(int i = 0; i < nums.size(); ++i)
            fre[nums[i]].emplace_back(i);
            
        vector<int> res;
        for(auto q: queries){
            int l = q[0], r = q[1];
            int tmp = 1e5;
            int p = -1;
            for(int i = 1; i <= 100; ++i){
                if(fre[i].empty()) continue;
                // exist a index in range [l, r]
                auto idx = lower_bound(fre[i].begin(), fre[i].end(), l);
                if(idx == fre[i].end() || *idx > r) continue;
                if(p != -1)
                    tmp = min(tmp, i - p);
                p = i;
            }
            if(tmp == 1e5) tmp = -1;
            res.push_back(tmp);
        }
        
        return res;
    }
};
