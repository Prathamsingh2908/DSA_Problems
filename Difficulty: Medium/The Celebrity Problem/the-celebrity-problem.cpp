class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        int top = 0;
        int down = n - 1;

        // Step 1: Find potential celebrity
        while (top < down) {
            if (mat[top][down] == 1) {
                // top knows down → top cannot be celebrity
                top++;
            } else {
                // top does NOT know down → down cannot be celebrity
                down--;
            }
        }

        int cand = top;

        // Step 2: Verify candidate
        for (int i = 0; i < n; i++) {
            if (i == cand) continue;

            // celebrity knows nobody & everyone knows celebrity
            if (mat[cand][i] == 1 || mat[i][cand] == 0)
                return -1;
        }

        return cand;
    }
};