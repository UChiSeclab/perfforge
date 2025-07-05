#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void check_long_substring_invariant(int n, int m) {
    if (n > m * 2) {  // Arbitrary threshold considering large `s` relative to `t`
        cerr << "Warning: Potential slowdown due to large `s` relative to `t`!" << endl;
        abort();
    }
}

void check_subsequence_verification_invariant(int n) {
    if (n > 150) { // Since n <= 200, checking when n is relatively high
        cerr << "Warning: Potential inefficiency in subsequence verification!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int n) {
    if (n > 180) { // Close to the upper limit
        cerr << "Warning: Inefficiency due to nested loop complexity!" << endl;
        abort();
    }
}

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    // Inserted checks for performance characteristics
    check_long_substring_invariant(n, m);  // Check after reading input
    check_subsequence_verification_invariant(n);  // Check before loops
    check_nested_loop_invariant(n);  // Check before loops

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (n - j + i - 1 < m) continue;
            int p = 0, q = 0;
            while (p < n) {
                if (i <= p && p <= j) p = j + 1;
                if (p < n && q < m && s[p] == t[q]) q++;
                p++;
            }
            if (q == m) ans = max(ans, j - i + 1);
        }
    }
    printf("%d\n", ans);
    return 0;
}