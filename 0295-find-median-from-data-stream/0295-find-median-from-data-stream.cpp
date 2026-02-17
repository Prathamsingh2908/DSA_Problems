#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> small; // Max-heap (left side)
    priority_queue<int, vector<int>, greater<int>> large; // Min-heap (right side)

public:
    MedianFinder() {}
    
    void addNum(int num) {
        // Move value through small to large to ensure correct ordering
        small.push(num);
        large.push(small.top());
        small.pop();

        // Maintain balance: small side keeps the extra element if count is odd
        if (small.size() < large.size()) {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        // Return top of larger heap for odd total, or average of tops for even total
        if (small.size() > large.size()) {
            return (double)small.top();
        } else {
            return (small.top() + large.top()) / 2.0;
        }
    }
};