    #include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;


class Solution {
public:
   
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        
        // Step 1: Sort both arrays in descending order
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        // Max-Heap to store {sum, {index_i, index_j}}
        priority_queue<pair<int, pair<int, int>>> pq;
        
        // Set to keep track of visited index pairs (i, j)
        set<pair<int, int>> visited;

        // Step 2: Push the largest possible sum into the heap
        pq.push({a[0] + b[0], {0, 0}});
        visited.insert({0, 0});

        vector<int> result;

        // Step 3: Iterate K times to get the K largest sums
        while (k-- > 0 && !pq.empty()) {
            pair<int, pair<int, int>> top = pq.top();
            pq.pop();

            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;

            result.push_back(sum);

            // Candidate 1: (i + 1, j)
            if (i + 1 < n && visited.find({i + 1, j}) == visited.end()) {
                pq.push({a[i + 1] + b[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            // Candidate 2: (i, j + 1)
            if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return result;
    }
};