// Queue and set. space is less more
class Logger {
public:
    /** Initialize your data structure here. */
    queue<pair<string, int>> q;
    unordered_set<string> st;
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while(q.size() && timestamp - q.front().second >= 10){
            st.erase(q.front().first);
            q.pop();
        }
        if(st.count(message)) return false;
        q.push({message, timestamp});
        st.insert(message);
        return true;
    }
};

// Simple map O(1)
class Logger {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> mp;
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp[message] > timestamp) return false;
        mp[message] = timestamp + 10;
        return true;
    }
};
