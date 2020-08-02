// Just Simulate. O(N). use deque two simulate
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int mx = *max_element(arr.begin(), arr.end()), ans = arr[0];
        deque<int> q(arr.begin(), arr.end());
        unordered_map<int,int> mp;
        while(1){
            if(q[0] == mx) return mx;
            int a = q.front(); q.pop_front();
            int b = q.front(); q.pop_front();
            if(b > a) swap(a, b);
            q.push_front(a);
            q.push_back(b);
            mp[a]++;
            if(mp[a] == k) return a;
        }
        return ans;
    }
};

// Autually, just find max
// so calculate, if win times equal to k. no nned to simulate
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int cur = arr[0], win = 0;
        for(int i = 1; i < arr.size(); ++i){
            if(arr[i] > cur){
                cur = arr[i];
                win = 0;
            }
            if(++win == k) break;
        }
        return cur;
    }
};
