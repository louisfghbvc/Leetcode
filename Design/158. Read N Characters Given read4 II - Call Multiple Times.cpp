// just implement, simulate.

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:    
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int j = 0; // autual chars
        while(j < n){
            if(i == len){
                i = 0;
                len = read4(res);
                if(len == 0) break;
            }
            buf[j] = res[i];
            i += 1;
            j += 1;
        }
        return j;
    }
private:
    char res[4];
    int i = 0, len = 0;
};
