// O(sqrt(N)). just observe, and greedy.

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2) return {};
        
        vector<long long> res;
        
        long base = 2;
        while(finalSum >= base){
            res.push_back(base);
            finalSum -= base;
            base += 2;
        }
        
        // recover
        if(finalSum > 0)
            res.back() += finalSum;
        
        return res;
    }
};
