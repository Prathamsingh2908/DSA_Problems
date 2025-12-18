#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int half_k = k / 2;
        long long base_profit = 0;

        for (int i = 0; i < n; ++i) {
            base_profit += (long long)prices[i] * strategy[i];
        }

        auto get_hold_gain = [&](int i) {
            return (long long)(0 - strategy[i]) * prices[i];
        };
        auto get_sell_gain = [&](int i) {
            return (long long)(1 - strategy[i]) * prices[i];
        };

        long long current_improvement = 0;
        for (int i = 0; i < half_k; ++i) {
            current_improvement += get_hold_gain(i);
        }
        for (int i = half_k; i < k; ++i) {
            current_improvement += get_sell_gain(i);
        }

        long long max_improvement = current_improvement;

        for (int i = 0; i < n - k; ++i) {
            current_improvement -= get_hold_gain(i);
            current_improvement -= get_sell_gain(i + half_k);
            current_improvement += get_hold_gain(i + half_k);
            current_improvement += get_sell_gain(i + k);

            max_improvement = max(max_improvement, current_improvement);
        }

        return base_profit + max(0LL, max_improvement);
    }
};