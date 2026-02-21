#include <vector>
#include <stack>

using namespace std;

class Solution {
  public:
    // Finds the first strictly smaller element to the right
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> s;

        // Traverse from right to left using a monotonic stack
        for (int i = n - 1; i >= 0; i--) {
            // Maintain stack elements smaller than current
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }

            if (!s.empty()) {
                result[i] = s.top();
            }

            s.push(arr[i]);
        }

        return result;
    }
};