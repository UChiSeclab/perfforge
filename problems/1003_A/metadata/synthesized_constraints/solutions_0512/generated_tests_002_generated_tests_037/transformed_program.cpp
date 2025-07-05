#include <bits/stdc++.h>
using namespace std;

// Function to check for performance bottlenecks
void check_high_frequency_of_value(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - high frequency of repeated value checks!" << endl;
        abort();
    }
}

void check_large_input_uniform_values(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - large input with uniform values!" << endl;
        abort();
    }
}

void check_dominating_single_value(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - one value dominates the input!" << endl;
        abort();
    }
}

int main() {
    int n, x;
    cin >> n;
    
    // Read the coins and count each value
    unordered_map<int, int> value_counts;
    for (int i = 0; i < n; i++) {
        cin >> x;
        value_counts[x]++;
    }
    
    // Check conditions after processing input
    check_high_frequency_of_value(value_counts.size() < n / 2); // e.g., only a few distinct values
    check_large_input_uniform_values(n > 80 && value_counts.size() < 10); // large n with few unique values
    check_dominating_single_value(n > 80 && value_counts[x] > n / 2); // more than half are the same value
    
    // Determine maximum frequency
    int max_frequency = 0;
    for (const auto& kvp : value_counts) {
        max_frequency = max(max_frequency, kvp.second);
    }
    
    cout << max_frequency << endl; // number of pockets needed
    return 0;
}