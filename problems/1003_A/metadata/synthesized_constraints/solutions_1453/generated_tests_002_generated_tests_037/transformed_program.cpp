#include <bits/stdc++.h>
using namespace std;

// Function to check high frequency invariant
void check_high_frequency_invariant(const vector<int>& frequency, int n) {
    for (int i = 0; i < frequency.size(); ++i) {
        if (frequency[i] > n / 2) {
            cerr << "Warning: Performance bottleneck condition triggered due to high frequency of value " << i << endl;
            abort();
        }
    }
}

// Function to check repetition invariant
void check_repetition_invariant(const vector<int>& coins, int n) {
    if (n >= 100) {
        unordered_map<int, int> valueCount;
        for (int coin : coins) {
            valueCount[coin]++;
        }
        for (const auto& pair : valueCount) {
            if (pair.second > n / 2) {
                cerr << "Warning: Performance bottleneck condition triggered due to repeated coin values." << endl;
                abort();
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> frequency(101, 0); // Assuming coins are in the range [1, 100]

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        frequency[a[i]]++;
    }

    // Check high frequency invariant
    check_high_frequency_invariant(frequency, n);

    // Check repetition invariant
    check_repetition_invariant(a, n);

    int b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) c++;
        }
        if (c > b) b = c;
        c = 0;
    }
    cout << b << "\n";
}