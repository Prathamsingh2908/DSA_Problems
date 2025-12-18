#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        // Convert to set for O(1) lookup
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        // dp[i] = true if s[0...i-1] can be segmented
        vector<bool> dp(n + 1, false);
        
        // Base case: empty string is valid
        dp[0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // If prefix s[0...j-1] is valid and s[j...i-1] is a dictionary word
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};