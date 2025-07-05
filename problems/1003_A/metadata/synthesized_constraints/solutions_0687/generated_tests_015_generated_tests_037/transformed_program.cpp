#include <bits/stdc++.h>
using namespace std;

// Function to check for frequent coin values
void check_frequent_value_invariant(int n, const vector<int>& frequency) {
    int maxFrequency = *max_element(frequency.begin(), frequency.end());
    if (n == 100 && maxFrequency > n / 2) {  // Trigger condition for slow performance
        cerr << "Warning: Performance bottleneck condition triggered for frequent coin values!" << endl;
        abort();
    }
}

// Function to check for high frequency of a single coin value
void check_high_frequency_invariant(int n, const vector<int>& frequency) {
    for (int freq : frequency) {
        if (freq > n / 2) {
            cerr << "Warning: Performance bottleneck condition triggered for high frequency of a single coin value!" << endl;
            abort();
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> frequency(101, 0); // Frequency array for coin values from 1 to 100

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        frequency[a[i]]++;
    }

    // Invariant checks
    check_frequent_value_invariant(n, frequency);  // Check for frequent values causing slowdown
    check_high_frequency_invariant(n, frequency);  // Check for high frequency of a single value

    int count1 = 0;
    for (int i = 0; i < n; i++) {
        int count2 = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) {
                count2++;
            }
        }
        count1 = max(count1, count2);
    }
    
    cout << count1;
    return 0;
}