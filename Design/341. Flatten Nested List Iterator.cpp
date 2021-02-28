// DFS, concept

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    queue<int> q;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }
    
    void helper(vector<NestedInteger> &nestedList){
        if(nestedList.empty()) return;
        for(auto &ni: nestedList){
            if(ni.isInteger()){
                q.push(ni.getInteger());
            }
            else{
                helper(ni.getList());
            }
        }
    }
    
    int next() {
        int val = q.front(); q.pop();
        return val;
    }
    
    bool hasNext() {
        return q.size() > 0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
