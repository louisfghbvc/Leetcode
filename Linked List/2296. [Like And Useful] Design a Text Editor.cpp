class TextEditor {
public:
    
    // idea: linked list
    TextEditor() {
        cursor = lt.begin();
    }
    
    void addText(string text) { // O(text.size())
        for (char c: text)
            lt.insert(cursor, c);
    }
    
    int deleteText(int k) { // O(K)
        int cnt = 0;
        for (int i = 0; i < k && cursor != lt.begin(); ++i) {
            lt.erase(prev(cursor));
            cnt++;
        }
        return cnt;
    }
    
    string getLeft() {
        string res;
        auto tmp = cursor;
        for (int i = 0; i < 10 && tmp != lt.begin(); ++i) {
            res += *prev(tmp);
            tmp--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    string cursorLeft(int k) {
        for (int i = 0; i < k && cursor != lt.begin(); ++i) {
            cursor--;
        }
        return getLeft();
    }
    
    string cursorRight(int k) {
        for (int i = 0; i < k && cursor != lt.end(); ++i) {
            cursor++;
        }
        return getLeft();
    }
    
private:
    list<char> lt; // string of the line
    list<char>::iterator cursor;
};



// Solution2, two deque
class TextEditor {
public:
    TextEditor() {
        
    }
    
    void addText(string text) {
        for (char c: text)
            left.push_back(c);    
    }
    
    int deleteText(int k) {
        int cnt = 0;
        for (int i = 0; i < k && left.size(); ++i) {
            left.pop_back();
            cnt++;
        }
        return cnt;
    }
    
    string fetch() {
        string res;
        int pos = left.size()-1;
        for (int i = 0; i < 10 && pos >= 0; ++i, --pos) {
            res.push_back(left[pos]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    string cursorLeft(int k) {
        for (int i = 0; i < k && left.size(); ++i) {
            right.push_front(left.back());
            left.pop_back();
        }
        return fetch();
    }
    
    string cursorRight(int k) {
        for (int i = 0; i < k && right.size(); ++i) {
            left.push_back(right.front());
            right.pop_front();
        }
        return fetch();
    }
    
private:
    deque<char> left, right;
};
