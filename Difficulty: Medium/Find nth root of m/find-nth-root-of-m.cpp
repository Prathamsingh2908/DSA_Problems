class Solution {
  public:
    
    int powerCheck(int mid, int n, int m) {
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = ans * mid;
            if (ans > m) return 1; // Optimization: stop early if we exceed m
        }
        if (ans == m) return 0;
        return 2;
    }

    int nthRoot(int n, int m) {
        // Edge case for m = 0 or m = 1
        if (m == 0) return 0;
        if (m == 1) return 1;

        int low = 1, high = m;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int status = powerCheck(mid, n, m);

            if (status == 0) {
                return mid; // Found the exact integer root
            } 
            else if (status == 1) {
                high = mid - 1; // mid^n is too large, look lower
            } 
            else {
                low = mid + 1; // mid^n is too small, look higher
            }
        }

        return -1; // No integer root found
    }
};