class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge_map;
        stack<int> s;

        // Use monotonic stack to find NGE for all elements in nums2
        for (int num : nums2) {
            while (!s.empty() && num > s.top()) {
                nge_map[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        vector<int> result;
        result.reserve(nums1.size());
        
        // Map NGE results back to nums1
        for (int num : nums1) {
            if (nge_map.count(num)) {
                result.push_back(nge_map[num]);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};