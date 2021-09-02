# Solution1
# Space is very bad. and each ops is large since need to sort and get ans
# Trie.

class Trie:
    def __init__(self):
        self.child = defaultdict(Trie)
        self.mp = defaultdict(int)
        
class AutocompleteSystem:
    
    def __init__(self, sentences: List[str], times: List[int]):
        self.root = Trie()
        self.iter = self.root
        self.word = ''
        for sentence, time in zip(sentences, times):
            self.add(sentence, time)
        
    def add(self, sentence: str, time: int):
        cur = self.root
        for c in sentence:
            cur = cur.child[c]
            cur.mp[sentence] -= time
        
    def input(self, c: str) -> List[str]:
        if c == '#': 
            self.add(self.word, 1)
            self.word, self.iter = '', self.root
            return []
        self.word += c
        self.iter = self.iter.child[c]
        return sorted(self.iter.mp.keys(), key = lambda x: (self.iter.mp[x], x))[:3]
        
# Solution2
# Space and Time is fast. and very simple.
# just calculate only once when first character. use prefix idea.
# first time O(NlogN). second time O(N).

class AutocompleteSystem:

    def __init__(self, sentences: List[str], times: List[int]):
        self.mp = Counter()
        self.cur = ''
        self.res = []
        for s, t in zip(sentences, times):
            self.mp[s] += t

    def input(self, c: str) -> List[str]:
        if c == '#':
            self.mp[self.cur] += 1
            self.cur, self.res = '', []
            return []        
        if not self.cur: # check if first char
            tmp = sorted([(-t, s) for s, t in self.mp.items() if s[0] == c])
            self.res = [s for _, s in tmp]
        else: # cache from prefix to find same
            l = len(self.cur)
            self.res = [s for s in self.res if len(s) > l and s[l] == c]
        self.cur += c
        return self.res[:3]

# Trie + DFS. scalable. each input get once dfs. input is O(NlogN).
# each trie node can add 3 string. make input O(1). Space and Time trade-off
class Trie:
    def __init__(self):
        self.child = defaultdict(Trie)
        self.word = ''
        self.hot = 0

class AutocompleteSystem:

    def __init__(self, sentences: List[str], times: List[int]):
        self.word = ''
        self.root = Trie()
        self.iter = self.root
        for s, t in zip(sentences, times):
            self.record(s, t)
    
    def record(self, sentence: str, time: int):
        cur = self.root
        for c in sentence:
            cur = cur.child[c]
        cur.word = sentence
        cur.hot += time
    
    def dfs(self, cur):
        if not cur: return []
        res = []
        if cur.word: res.append((-cur.hot, cur.word)) 
        for ch in cur.child.values():
            res += self.dfs(ch)
        return res
    
    def input(self, c: str) -> List[str]:
        if c == '#':
            self.record(self.word, 1)
            self.iter = self.root
            self.word = ''
            return []
        self.iter = self.iter.child[c]
        self.word += c
        return [word for fre, word in sorted(self.dfs(self.iter))[:3]]
