// BIT version, Dynamic prefix and rank. O(logNlogN). key point is remember the duplicate condition  [l, r]. WA. GG

class MKAverage {
public:
    struct BIT{
        int N = 100005;
        long arr[100005] = {};
        void add(int x, int v){
            for(++x; x < N; x += x&-x)
                arr[x] += v;
        }
        long sum(int x){
            long res = 0;
            for(++x; x; x -= x&-x)
                res += arr[x];
            return res;
        }
        int getKth(int k){ // k: index from 1
            int l = 0, r = N;
            while(l < r){
                int mid = (l+r)/2;
                int tmp = sum(mid);
                if(tmp >= k) r = mid;
                else l = mid+1;
            }
            return l;
        }
    };
    
    int M, K;
    queue<int> q;
    BIT rank, pre;
    
    MKAverage(int m, int k) {
        M = m;
        K = k;
    }
    
    void addElement(int num) {
        q.push(num);
        rank.add(num, 1);
        pre.add(num, num);
        while(q.size() > M){
            rank.add(q.front(), -1);
            pre.add(q.front(), -q.front());
            q.pop();
        }
    }
    
    int calculateMKAverage() {
        if(q.size() < M) return -1;
        int nl = rank.getKth(K);
        int nr = rank.getKth(M - K);
        long ans =  pre.sum(nr) - pre.sum(nl);
        ans += (rank.sum(nl) - K) * nl;
        ans -= (rank.sum(nr) - (M-K)) * nr;
        return ans / (M - 2*K);
    }
};

// Cool 3 balance multiset.
class MKAverage {
public:
    int M, K;
    long sum = 0;
    multiset<int> left, mid, right;
    queue<int> q;
    
    MKAverage(int m, int k) : M(m), K(k){
        
    }
    
    void add(int x){
        left.insert(x);
        if(left.size() > K){
            auto it = prev(left.end());
            mid.insert(*it);
            sum += *it;
            left.erase(it);
        }
        if(mid.size() > M - 2*K){
            auto it = prev(mid.end());
            right.insert(*it);
            sum -= *it;
            mid.erase(it);
        }
    }
    
    void remove(int x){
        if(*left.rbegin() >= x)
            left.erase(left.find(x));
        else if(*mid.rbegin() >= x){
            auto it = mid.find(x);
            sum -= *it;
            mid.erase(it);
        }
        else right.erase(right.find(x));
        
        if(left.size() < K){
            left.insert(*mid.begin());
            sum -= *mid.begin();
            mid.erase(mid.begin());
        }
        if (mid.size() < M - 2*K) {
            mid.insert(*right.begin());
            sum += *right.begin();
            right.erase(right.begin());
        }
    }
    
    void addElement(int num) {
        add(num);
        q.push(num);
        if(q.size() > M){
            remove(q.front());
            q.pop();
        }
    }
    
    int calculateMKAverage() {
        if(left.size() + mid.size() + right.size() < M) return -1;
        return sum / (M - 2*K);
    }
};
