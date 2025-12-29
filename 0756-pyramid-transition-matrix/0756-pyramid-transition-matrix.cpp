#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // Maps a pair of characters (e.g., "AB") to all possible top characters (e.g., "CD")
    unordered_map<string, string> adj;
    // Memoization map to store if a specific row configuration can reach the top
    unordered_map<string, bool> memo;

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        adj.clear();
        memo.clear();
        
        // Pre-process allowed transitions for faster lookup
        for (const string& s : allowed) {
            adj[s.substr(0, 2)] += s[2];
        }
        
        return solve(bottom, "");
    }

private:
    bool solve(string curr, string next) {
        // Base Case: We've reached the single block at the top
        if (curr.length() == 1) return true;

        // If we finished building the current 'next' row, move up to the next level
        if (next.length() == curr.length() - 1) {
            return solve(next, "");
        }

        // Memoization check: identify state by current row + progress on next row
        string state = curr + "#" + next;
        if (memo.count(state)) return memo[state];

        // Get the two blocks we are currently sitting on
        string base = curr.substr(next.length(), 2);
        
        // If there are allowed blocks to go on top of this base
        if (adj.count(base)) {
            for (char top : adj[base]) {
                if (solve(curr, next + top)) {
                    return memo[state] = true;
                }
            }
        }

        return memo[state] = false;
    }
};