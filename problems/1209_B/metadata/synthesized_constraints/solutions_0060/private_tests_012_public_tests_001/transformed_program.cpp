#include <bits/stdc++.h>
using namespace std;

// Checker functions as described in Phase 3
void check_iteration_count_invariant(int n, int a[], int size) {
    bool frequentToggling = false;
    for (int i = 0; i < size; ++i) {
        if (a[i] <= 2) { // a small value indicates frequent toggling
            frequentToggling = true;
            break;
        }
    }
    if (n > 90 && frequentToggling) { // Check for near upper limit and frequent toggling
        cerr << "Warning: Performance bottleneck condition - high iteration count!" << endl;
        abort();
    }
}

void check_frequent_toggling_invariant(int a[], int size) {
    int frequentToggleCount = 0;
    for (int i = 0; i < size; ++i) {
        if (a[i] <= 2) { // Assumed threshold for frequent toggling
            frequentToggleCount++;
        }
    }
    if (frequentToggleCount > size / 2) { // More than half frequently toggle
        cerr << "Warning: Performance bottleneck condition - frequent toggling!" << endl;
        abort();
    }
}

void check_initial_state_invariant(const string &s, int a[], int size) {
    int initiallyOnCount = 0;
    for (char c : s) {
        if (c == '1') {
            initiallyOnCount++;
        }
    }
    
    int frequentToggleCount = 0;
    for (int i = 0; i < size; ++i) {
        if (a[i] <= 2) { // Assumed threshold for frequent toggling
            frequentToggleCount++;
        }
    }

    if (initiallyOnCount > size / 2 && frequentToggleCount > size / 2) {
        cerr << "Warning: Performance bottleneck condition - initial state and frequent toggling!" << endl;
        abort();
    }
}

int main() {
    int n, i, r = 0, j, max = 0;
    int a[100], b[100];
    string s;
    cin >> n;
    cin >> s;
    for (i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    // Insert checks after input and before main processing
    check_iteration_count_invariant(n, a, n);
    check_frequent_toggling_invariant(a, n);
    check_initial_state_invariant(s, a, n);

    for (j = 0; j < n; j++) {
        if (s[j] == '1') {
            r++;
        }
    }
    if (r > max) {
        max = r;
    }
    for (i = 0; i < n * 1000; i++) {
        r = 0;
        for (j = 0; j < n; j++) {
            if ((((i - b[j]) % a[j] == 0) && (i >= b[j]))) {
                if (s[j] == '1') {
                    s[j] = '0';
                } else {
                    s[j] = '1';
                }
            }
        }
        for (j = 0; j < n; j++) {
            if (s[j] == '1') {
                r++;
            }
        }
        if (r > max) {
            max = r;
        }
    }
    cout << max;
}