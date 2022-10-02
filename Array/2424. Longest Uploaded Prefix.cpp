class LUPrefix {
public:
    
    int missing = 1; // not upload video
    vector<bool> vis;
    LUPrefix(int n) {
        vis.resize(n+5);
    }
    
    void upload(int video) { 
        vis[video] = true;
    }
    
    int longest() { // amortized O(1)
        while (vis[missing]) missing++;
        return missing-1; // [1, missing-1] cover
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
