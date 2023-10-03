#include <iostream>
#include <vector>

using namespace std;

int knapsackWithRepetition(int capacity, vector<int> weights, vector<int> values, vector<int> repetitions) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);

    for (int w = 1; w <= capacity; ++w) {
        for (int i = 0; i < n; ++i) {
            if (weights[i] <= w) {
                dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
            }
        }
    }

    return dp[capacity];
}

int main() {
    int capacity = 10;
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    vector<int> repetitions = {2, 1, 3, 2};

    int max_value = knapsackWithRepetition(capacity, weights, values, repetitions);

    cout << "Maximum value that can be obtained (with repetitions): " << max_value << endl;

    return 0;
}
