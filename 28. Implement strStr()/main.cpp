class Solution {
public:
    int strStr(string haystack, string needle) {
        int p1 = 0; int p2 = 0;
        int idx = -1;
        
        while (p1 < haystack.size() and p2 < needle.size()) {
            if (haystack[p1] == needle[p2]) {
                if (idx < 0)
                    idx = p1;
                ++p1; ++p2;
            } else {
                if (idx >= 0) {
                    p1 = idx + 1;
                    idx = -1;   
                } else
                    ++p1;
                p2 = 0;
            }
        }
        
        return p2 < needle.size() ? -1 : idx;
    }
};
