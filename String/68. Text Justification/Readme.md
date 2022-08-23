# [68. Text Justification](https://leetcode.com/problems/text-justification/)

###### tags: `leetcode` `hard` `string`

[TOC]

## Description
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

## Way1 - Two Pointers, Greedy

```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // each line will exactly maxWidth chars
        // each word will be split at least one blank
        // last line left-justified
        // idea: put line by line
        
        vector<string> res;
        
        int n = words.size();
        for (int i = 0, j; i < n; i = j) {
            j = i;
            
            int width = 0; // only calculate the length(with 1 blank)
            int space = 0;
            while (j < n && width + space + words[j].size() <= maxWidth) {
                width += words[j].size();
                j++;
                space++;
            }
            
            string line;
            line += words[i];
            if (space != 1) {
                if (j != n) { // not last line
                    int perBlank = (maxWidth - width) / (space-1);
                    int extraSpace = (maxWidth - width) % (space-1);
                    for (int k = i+1, idx = 0; k < j; ++k, ++idx) {
                        if (idx < extraSpace)
                            line += ' ';
                        line += string(perBlank, ' ');
                        line += words[k];
                    }
                }
                else {
                    for (int k = i+1; k < j; ++k) {
                        line += ' ';
                        line += words[k];
                    }
                }
            }
            
            if (line.size() < maxWidth) // padding space in the end
                line += string(maxWidth-(int)line.size(), ' ');
            res.push_back(line);
        }
        
        return res;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(n\*maxWidth) | O(n\*c) |
