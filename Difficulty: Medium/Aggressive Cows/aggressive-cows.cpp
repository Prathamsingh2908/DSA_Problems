class Solution {
public:
    // Helper function to check if we can place k cows with a minimum distance 'dist'
    bool canWePlace(vector<int> &stalls, int dist, int cows) {
        int cntCows = 1;
        int last = stalls[0];
        
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - last >= dist) {
                cntCows++;
                last = stalls[i];
            }
            if (cntCows >= cows) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        // Step 1: Sort stalls to apply binary search on the distance
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();

        // Step 2: Define binary search range for the minimum distance
        int low = 1;
        int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canWePlace(stalls, mid, k)) {
                ans = mid;    // This distance is possible, try for a larger one
                low = mid + 1;
            } else {
                high = mid - 1; // Distance too large, try smaller
            }
        }
        return ans; // Or return high, both will be the same after the loop
    }
};