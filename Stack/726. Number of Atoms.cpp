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
