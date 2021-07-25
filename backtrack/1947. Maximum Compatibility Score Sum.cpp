// Use sort and simple next_permutation.
// O(N!MN)

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        int n = students[0].size();
        
        int mx = 0;
        sort(students.begin(), students.end());
        do{
            int sum = 0;
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    sum += students[i][j] == mentors[i][j];
                }
            }
            mx = max(sum, mx);
            
        }while(next_permutation(students.begin(), students.end()));
        return mx;
    }
};

// Use dp + bitmask. but since n = 8.
