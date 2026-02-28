class Solution {
public:
    vector<int> buildLPS(const string& pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);

        int len = 0;   // length of previous longest prefix suffix
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int n = haystack.size(), m = needle.size();
        vector<int> lps = buildLPS(needle);

        int i = 0; // index for haystack
        int j = 0; // index for needle

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == m) return i - j; // match found
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1; // not found
    }
};