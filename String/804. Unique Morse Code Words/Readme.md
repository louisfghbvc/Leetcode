# [804. Unique Morse Code Words](https://leetcode.com/problems/unique-morse-code-words/)

###### tags: `leetcode` `easy` `hash table`

[TOC]

## Description


Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.

```
For example, "cab" can be written as "-.-..--...", 
which is the concatenation of "-.-.", ".-", and "-...".
We will call such a concatenation the transformation of a word.
```
Return the number of different transformations among all words we have.

## Way1 

```cpp
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // idea: encode the word, and use a set to record the string
        
        vector<string> arr = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        
        unordered_set<string> diff;
        
        for (auto &s: words) {
            string encode;
            for (char c: s)
                encode += arr[c-'a'];
            diff.insert(encode);
        }
        
        return diff.size();
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(n\*m) | O(n\*m) |
