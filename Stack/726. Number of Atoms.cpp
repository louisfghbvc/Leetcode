class Solution {
public:

    void product(unordered_map<string, int>& mp, int cnt) {
        for (auto &[k, v]: mp)
            v *= cnt;
    }

    void add(unordered_map<string, int>& a, unordered_map<string, int>& b) {
        for (auto &[k, v]: b)
            a[k] += v;
    }

    string countOfAtoms(string formula) {
        // goal: count each atoms
        // idea:
        // need to know atoms: uppercase + lowercase*
        // (OH)2 -> O2H2
        // when () -> need to make it as a group
        // () 2 -> all elements in () times number
        // using stack record a map {string, int}

        // do () as a sub

        stack<unordered_map<string, int>> st;
        unordered_map<string, int> cur;
        int n = formula.size();
        for (int i = 0; i < formula.size(); ) {
            char c = formula[i];
            i++;
            if (isupper(c)) {
                string name(1, c);
                int cnt = 0;
                while (i < n && islower(formula[i])) {
                    name += formula[i];
                    i++;
                }
                // digit
                if (i < n && isdigit(formula[i])) {
                    while (i < n && isdigit(formula[i])) {
                        cnt = cnt * 10 + formula[i]-'0';
                        i++;
                    }
                }
                else {
                    cnt = 1;
                }
                cur[name] += cnt;
            }
            else if (c == '(') {
                st.push(cur);
                cur.clear();
            }
            else if (c == ')') {
                int cnt = 0;
                if (i < n && isdigit(formula[i])) {
                    while (i < n && isdigit(formula[i])) {
                        cnt = cnt * 10 + formula[i]-'0';
                        i++;
                    }
                }
                else {
                    cnt = 1;
                }
                product(cur, cnt);
                auto prev = st.top(); st.pop();
                add(prev, cur);
                swap(cur, prev);
            }
        }

        // output
        vector<pair<string, int>> arr(cur.begin(), cur.end());
        sort(arr.begin(), arr.end());
        string res;
        for (auto &[k, v]: arr) {
            res += k;
            if (v > 1)
                res += to_string(v);
        }
        return res;
    }
};


// Optimized, Preprocessing the multiplier.
// TC: O(nlogn)

class Solution {
public:

    // (()2)3
    vector<int> buildMul(string &s) {
        int n = s.size();
        vector<int> res(n, 1); // res[i]: starting from index i, the right multiple
        int runningMul = 1;
        int mul = 1;
        stack<int> st;
        for (int i = s.size()-1; i >= 0; --i) {
            if (isdigit(s[i])) {
                string tmp;
                while (i >= 0 && isdigit(s[i])) {
                    res[i] = runningMul; // remember to setup mul
                    tmp += s[i];
                    i--;
                }
                reverse(tmp.begin(), tmp.end());
                mul = stoi(tmp);
                i++; // to last digit index
            }
            else if (s[i] == ')') {
                st.push(mul);
                runningMul *= mul;
                mul = 1;
            }
            else if (s[i] == '(') {
                runningMul /= st.top(); 
                st.pop();
                mul = 1;
            }
            else {
                mul = 1;
            }
            res[i] = runningMul;
        }
        return res;
    }

    string countOfAtoms(string formula) {
        // goal: count each atoms
        // idea:
        // need to know atoms: uppercase + lowercase*
        // (OH)2 -> O2H2
        // when () -> need to make it as a group
        // () 2 -> all elements in () times number
        // using stack record a map {string, int}

        // do () as a sub

        // improve:
        // we are doing the multiple table first
        // each time we don't need to do the recursive, we can get the final answer

        auto table = buildMul(formula);

        unordered_map<string, int> cur;
        int n = formula.size();
        for (int i = 0; i < n;) {
            if (isupper(formula[i])) {
                string name(1, formula[i]);
                // lowercase
                i++;
                while (i < n && islower(formula[i])) {
                    name += formula[i];
                    i++;
                }
                // do number
                int cnt = isdigit(formula[i]) ? 0 : 1;
                if (isdigit(formula[i])) {
                    while (i < n && isdigit(formula[i])) {
                        cnt = cnt*10 + formula[i]-'0';
                        i++;
                    }
                }
                cur[name] += cnt * table[i-1];
            }
            else {
                i++;
            }
        }

        // output
        vector<pair<string, int>> arr(cur.begin(), cur.end());
        sort(arr.begin(), arr.end());
        string res;
        for (auto &[k, v]: arr) {
            res += k;
            if (v > 1)
                res += to_string(v);
        }
        return res;
    }
};
