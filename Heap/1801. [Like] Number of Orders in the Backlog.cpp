// Can use heap =.=. yep...
// O(NlogN).

class Solution {
public:
    int mod = 1e9+7;
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        map<int, int> buy;
        map<int, int> sell;
        
        for(auto &od: orders){
            int val = od[0], num = od[1], type = od[2];
            // cur buy, check sell smallest
            if(type == 0){
                while(sell.size() && sell.begin()->first <= val){
                    if(num <= 0) break;
                    int sub = min(num, sell.begin()->second);
                    sell.begin()->second -= sub;
                    if(sell.begin()->second == 0){
                        sell.erase(sell.begin()->first);
                    }
                    num -= sub;
                }
                buy[val] += num;
            }
            else{
                while(buy.size() && buy.rbegin()->first >= val){
                    if(num <= 0) break;
                    int sub = min(num, buy.rbegin()->second);
                    buy.rbegin()->second -= sub;
                    if(buy.rbegin()->second == 0){
                        buy.erase(buy.rbegin()->first);
                    }
                    num -= sub;
                }
                sell[val] += num;
            }
        }
        
        int res = 0;
        for(auto &[k, v]: buy){
            res += v;
            res %= mod;
        }
        for(auto &[k, v]: sell){
            res += v;
            res %= mod;
        }
        return res;
    }
};
