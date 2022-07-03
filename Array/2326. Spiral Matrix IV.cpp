/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // goal: generate the matrix, clockwise direction
        // idea: traverse the linkedlist
        
        vector<vector<int>> res(m, vector<int>(n, -1));
        
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        auto dfs = [&](const auto &self, int i, int j, int d) -> void {
            if (!head) return;
            res[i][j] = head->val; head = head->next;
            
            for (int k = 0; k < 4; ++k) {
                int ni = i+dir[(k+d)%4][0], nj = j+dir[(k+d)%4][1];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n || res[ni][nj] != -1) continue;
                self(self, ni, nj, (k+d)%4);
            }
            
        };
        
        dfs(dfs, 0, 0, 0);
        
        return res;
    }
};
