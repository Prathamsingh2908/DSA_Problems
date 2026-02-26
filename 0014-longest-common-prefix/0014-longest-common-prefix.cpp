class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        for (int i = 0; i < strs[0].size(); i++) {       // each char position
            char c = strs[0][i];                           // char from first string

            for (int j = 1; j < strs.size(); j++) {       // check all other strings
                if (i >= strs[j].size() || strs[j][i] != c)  // out of bounds OR mismatch
                    return strs[0].substr(0, i);           // return prefix so far
            }
        }
        return strs[0];  // first string itself is the common prefix
    }
};