# py trie is awesome, use defaultdict to if not exist new TrieNode
# super fast. each ops just go through trie.

class TrieNode:
    def __init__(self):
        self.child = defaultdict(TrieNode)
        self.content = ""
    
class FileSystem:
    
    def __init__(self):
        self.root = TrieNode()
    
    def searchOrAdd(self, path: str):
        cur = self.root
        if len(path) == 1: return cur
        lt = path.split('/')[1:]
        for word in lt:
            cur = cur.child[word]
        return cur
    
    def ls(self, path: str) -> List[str]:
        cur = self.searchOrAdd(path)
        if cur.content: # file name
            return [path.split('/')[-1]]
        return sorted(cur.child.keys())
        
    def mkdir(self, path: str) -> None:
        self.searchOrAdd(path)
        
    def addContentToFile(self, filePath: str, content: str) -> None:
        cur = self.searchOrAdd(filePath)
        cur.content += content

    def readContentFromFile(self, filePath: str) -> str:
        cur = self.searchOrAdd(filePath)
        return cur.content


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)
