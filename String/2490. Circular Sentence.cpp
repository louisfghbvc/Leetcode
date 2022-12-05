class Solution {
public:
    bool isCircularSentence(string sentence) {
        // circular:
        // The last character of a word is equal to the first character of the next word.
        // The last character of the last word is equal to the first character of the first word.
        // idea: parsing the string
        
        stringstream ss(sentence);
        vector<string> arr;
        string word;
        while (ss >> word)
            arr.push_back(word);
        
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            string cur = arr[i];
            string next = arr[(i+1)%n];
            if (cur.back() != next[0])
                return false;
        }
        
        return true;
    }
};

// Solution2: can improve to O(1) space
