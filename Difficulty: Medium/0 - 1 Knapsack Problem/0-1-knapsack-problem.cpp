class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // base case — fill row 0
        for(int w = wt[0]; w <= W; w++)
            dp[0][w] = val[0];

        // fill rest of table
        for(int ind = 1; ind < n; ind++) {
            for(int w = 0; w <= W; w++) {
                int notTake = dp[ind - 1][w];
                int take = INT_MIN;
                if(wt[ind] <= w)
                    take = val[ind] + dp[ind - 1][w - wt[ind]];
                dp[ind][w] = max(take, notTake);
            }
        }

        return dp[n - 1][W];
    }
};