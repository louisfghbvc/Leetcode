class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        // goal: return the most popular creator and video
        // idea: hashtable, creators -> views, creaters -> min ids
        
        int n = ids.size();
        unordered_map<string, long> totalViews;
        
        long mx = 0;
        for (int i = 0; i < n; ++i) {
            totalViews[creators[i]] += views[i];
            mx = max(mx, totalViews[creators[i]]);
        }
        
        unordered_map<string, string> mnIds;
        unordered_map<string, int> highestViews;
        for (int i = 0; i < n; ++i) {
            string s = creators[i];
            if (highestViews[s] < views[i] || (highestViews[s] == views[i] && (!mnIds.count(s) || mnIds[s] > ids[i]))) {
                highestViews[s] = views[i];
                mnIds[s] = ids[i];
            }
        }
        
        vector<vector<string>> res;
        for (auto &[s, f]: totalViews) {
            if (f == mx)
                res.push_back({s, mnIds[s]});
        }
        
        return res;
    }
};


// dummy, ver2
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        // goal: return the most popular creator and video
        // idea: hashtable, creators -> views, creaters -> min ids
        
        int n = ids.size();
        unordered_map<string, vector<pair<int, string>>> most_views; // (-views, str) 
        unordered_map<string, long> popular; // 
        
        long mx = 0;
        for (int i = 0; i < n; ++i) {
            popular[creators[i]] += views[i];
            mx = max(mx, popular[creators[i]]);
            most_views[creators[i]].push_back({-views[i], ids[i]});
        }
        
        vector<vector<string>> res;
        for (auto &[s, f]: popular) {
            if (f == mx) {
                auto &tmp = most_views[s];
                sort(tmp.begin(), tmp.end());
                res.push_back({s, tmp[0].second});
            }
        }
        
        return res;
    }
};
