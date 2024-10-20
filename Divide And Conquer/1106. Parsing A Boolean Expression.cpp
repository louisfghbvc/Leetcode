class Solution {
public:

    bool eval(string& s, int& i) {
        char ch = s[i++];
        if (ch == 't') return true;
        if (ch == 'f') return false;
        if (ch == '!') {
            i++; // (
            auto res = eval(s,i);
            i++; // )
            return !res;
        }

        // and/or
        vector<bool> tmp;
        i++; // (
        tmp.push_back(eval(s, i));
        while (s[i] != ')') {
            i++; // ,
            tmp.push_back(eval(s, i));
        }
        i++; // )

        if (ch == '|') {
            return any_of(tmp.begin(), tmp.end(), [](bool b) { return b; });
        }
        return all_of(tmp.begin(), tmp.end(), [](bool b) { return b; });
    }

    bool parseBoolExpr(string expression) {
        // goal: find the expr final value
        
        // idea:
        // f/t
        // !()
        // &(expr,expr,expr)
        // |(...)

        // think the recursive
        // &(!(f),|(t))

        // ! => 

        // &(t,t)

        // fail!!
        // we can't handle , good
        // need go deeper and deeper
        // after looking the solution, we can use a index to easy handle

        int i = 0;
        return eval(expression, i);
    }
};
