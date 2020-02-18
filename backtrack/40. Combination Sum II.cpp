//4ms 9MB
class Solution {
public:
	void dfs(int v, int &t, vector<vector<int>> &res, vector<int> &tmp, vector<bool> &vis, vector<int> &arr, int st){
		if(v == t){
			res.push_back(tmp);
		}
		for(int i = st; i < arr.size() && v + arr[i] <= t; ++i){
			if(vis[i]) continue;
			vis[i] = true;
			tmp.push_back(arr[i]);
			dfs(v + arr[i], t, res, tmp, vis, arr, i + 1);
			tmp.pop_back();
			vis[i] = false;
			while(i < arr.size() - 1 && arr[i] == arr[i + 1]) i++;
		}
	} 
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());

		vector<bool> vis(candidates.size(), 0);
		vector<vector<int>> res;
		vector<int> tmp;

		dfs(0, target, res, tmp, vis, candidates, 0);

		return res;
	}
};
