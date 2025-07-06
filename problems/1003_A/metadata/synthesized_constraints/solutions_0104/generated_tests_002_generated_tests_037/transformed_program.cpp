#include <bits/stdc++.h>
using namespace std;

// Checker for high frequency of duplicate values
void check_high_frequency_invariant(const vector<int>& counts, int n) {
    int max_count = *max_element(counts.begin(), counts.end());
    if (max_count > n / 2) {  // Example threshold
        cerr << "Warning: Performance bottleneck triggered - high frequency of duplicate values!" << endl;
        abort();
    }
}

// Checker for large input size with nested loop issues
void check_large_input_invariant(int n) {
    if (n > 90) {  // Threshold close to upper limit
        cerr << "Warning: Performance bottleneck triggered - large input size with potential nested loop issue!" << endl;
        abort();
    }
}

// Checker for inefficient counting mechanism
void check_inefficient_counting_invariant(int unique_count, int n) {
    if (unique_count > n / 2) {  // Example threshold
        cerr << "Warning: Performance bottleneck triggered - inefficient counting mechanism!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;

    // Perform check for large input size
    check_large_input_invariant(n);

    int x;
    vector<int> v1;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v1.push_back(x);
    }

    int occ, count = 0;
    vector<int> v2;
    set<int> unique_values;  // To track unique elements

    for (int i = 0; i < n; i++) {
        occ = v1[i];
        unique_values.insert(occ);  // Collect unique elements
        for (int j = 0; j < n; j++) {
            if (occ == v1[j]) count++;
        }
        v2.push_back(count);
        count = 0;
    }

    // Perform checks for high frequency and inefficient counting
    check_high_frequency_invariant(v2, n);
    check_inefficient_counting_invariant(unique_values.size(), n);

    sort(v2.begin(), v2.end());
    int l = v2.size();
    cout << v2[l - 1];
    return 0;
}