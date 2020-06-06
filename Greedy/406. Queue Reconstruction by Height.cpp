// First think is sort by k, and max height first.
// Calculate how many people's height are greater than this person
// O(N^2)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(), [](vector<int> &a, vector<int> &b) {
           return a[1]<b[1] || (a[1]==b[1] && a[0]>b[0]); 
        });
        vector<vector<int>> ans;
        for(const auto &p: people){
            int k = 0, i;
            for(i = 0; i < ans.size() && k < p[1]; ++i){
                if(ans[i][0] >= p[0]) k++;
            }
            ans.insert(ans.begin()+i, p);
        }
        return ans;
    }
};

// Better, Sort by height. and k is index of insert
// don't need to calculate how many people's height are greater than this person
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(), [](vector<int> &a, vector<int> &b) {
           return a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]); 
        });
        vector<vector<int>> ans;
        for(const auto &p: people){
            ans.insert(ans.begin()+p[1], p);
        }
        return ans;
    }
};
