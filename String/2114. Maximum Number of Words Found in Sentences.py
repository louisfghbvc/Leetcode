# split the string and calculate the length

class Solution:
    def mostWordsFound(self, texts: List[str]) -> int:
        return max(len(text.split()) for text in texts)
