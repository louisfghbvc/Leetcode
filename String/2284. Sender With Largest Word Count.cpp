class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        // goal: find the largest messages word count, find the sender
        // idea: hashtable to record the name -> word count 
        
        unordered_map<string, int> mp;
        
        for (int i = 0; i < messages.size(); ++i) {
            string &s = messages[i];
            string &name = senders[i];
            
            int word_cnt = 1 + count(s.begin(), s.end(), ' ');
            
            mp[name] += word_cnt;
        }
        
        
        // find the maximum name
        
        string ans;
        
        for (auto &[name, cnt]: mp) {
            if (ans.empty() || cnt > mp[ans] || cnt == mp[ans] && name > ans) {
                ans = name;
            }
        }
        
        return ans;
    }
};
