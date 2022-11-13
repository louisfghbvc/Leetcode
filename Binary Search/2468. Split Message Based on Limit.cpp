class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        // goal: must split the message, each part = limit
        // idea: binary search the part
        // s = 37, limit=9
        // 37 / 14 = 2 ... 9
        
        int n = message.size();
        
        vector<string> res;
        auto check = [&](int part) -> int { // need to divide to part
            res.clear();
            string part_s = to_string(part); // "14"
            
            int num = 1;
            int i = 0;
            while (num <= part) {
                string suf = "<" + to_string(num) + "/" + part_s + ">";
                int len_need = limit - (int)suf.size(); // fit the limit
                if (len_need <= 0) return -1;
                string pre;
                while (len_need && i < message.size()) {
                    pre += message[i];
                    i++;
                    len_need--;
                }
                if (num != part && len_need != 0) // too many part
                    return -1;
                if (pre.empty())  // last part can not be empty
                    return -1;
                res.push_back(pre + suf);
                num++;
            }
            
            if (i != message.size()) return 1; // too less part
            
            return 0;
        };
        
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l+r)/2;
            int status = check(mid);
            if (status == 0)
                return res;
            else if (status > 0) // part not enough, need more part
                l = mid+1;
            else // too many part
                r = mid-1;
        }
        return {};
    }
};
