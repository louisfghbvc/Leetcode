// O(N). just dfs, can also input and build
class Solution {
public:
    typedef pair<int, int> ii;
    deque<ii> arr;
    TreeNode* dfs(int p = -1){
        if(arr.empty() || arr[0].second <= p) return NULL;
        ii ele = arr.front(); arr.pop_front();
        TreeNode* root = new TreeNode(ele.first);
        root->left = dfs(ele.second);
        root->right = dfs(ele.second);
        return root;
    }
    TreeNode* recoverFromPreorder(string S) {
        int i = 0, n = S.size();
        string tmp;
        for(tmp = ""; i < n && S[i] != '-'; ++i) tmp += S[i];
        arr.push_back({stoi(tmp), 0});
        while(i < n){
            int d = 0;
            for(; i < n && S[i] == '-'; ++i, ++d);
            for(tmp = ""; i < n && S[i] != '-'; i++) tmp += S[i];
            arr.push_back({stoi(tmp), d});
        }
        return dfs();
    }
};
