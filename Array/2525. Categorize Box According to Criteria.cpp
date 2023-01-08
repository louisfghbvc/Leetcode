class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool b = false;
        bool h = false;
        if (length >= 1e4 || width >= 1e4 || height >= 1e4 || 1LL*length*height*width >= 1e9) 
            b = 1;
        if (mass >= 100)
            h = 1;
        if (b && h) return "Both";
        if (!b && !h) return "Neither";
        return b ? "Bulky" : "Heavy";
    }
};
