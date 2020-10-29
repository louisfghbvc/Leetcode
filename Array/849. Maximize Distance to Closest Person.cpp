// build next array, and for each 0, calculate. O(N).
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> l(n);
        vector<int> r(n);
        l[0] = seats[0] ? 0 : n;
        for(int i = 1; i < n; ++i){
            if(seats[i] == 1){
                l[i] = i;
            }
            else{
                l[i] = l[i-1];
            }
        }
        r[n-1] = seats[n-1] ? n-1 : n;
        for(int i = n-2; i >= 0; --i){
            if(seats[i] == 1){
                r[i] = i;
            }
            else{
                r[i] = r[i+1];
            }
        }
        int res = 0;
        for(int i = 0; i < n; ++i){
            if(!seats[i]){
                int a = r[i] == n ? n : abs(r[i]-i);
                int b = l[i] == n ? n : abs(l[i]-i);
                res = max(min(a, b), res);
            }
        }
        return res;
    }
};

// Autually 3 case. group by zero. so from begin or from end or between.
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int res = 0, k = 0;
        for(int i = 0; i < n; ++i) if(seats[i]){
            res = max(res, i);
            break;
        }
        for(int i = n-1; i >= 0; --i) if(seats[i]){
            res = max(res, n-1-i);
            break;
        }
        for(int i = 0; i < n; ++i){
            if(seats[i]){
                k = 0;
            }
            else{
                k++;
                res = max(res, (k+1)/2);
            }
        }
        return res;
    }
};

// One pass Same as above.
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int res = 0, last = -1;
        for(int i = 0; i < n; ++i){
            if(seats[i]){
                res = last < 0 ? i : max(res, (i-last)/2);
                last = i;
            }
        }
        res = max(res, n-1-last);
        return res;
    }
};

// Rewrite again.
// O(N).
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0, n = seats.size();
        int prev = -1;
        for(int i = 0; i < n; ++i){
            if(seats[i]){
                if(prev < 0) res = max(res, i);
                else res = max(res, (i-prev)/2);
                prev = i;
            }
            else if(i == n-1){
                res = max(res, i-prev);
            }
        }
        return res;
    }
};
