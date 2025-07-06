#include <bits/stdc++.h>
using namespace std;

int n, m, a[10001], b[10001], ans = 0;

void check_sorting_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: sorting_invariant triggered - inefficient sorting for significant m" << endl;
        abort();
    }
}

void check_selection_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: selection_invariant triggered - inefficient matchbox selection" << endl;
        abort();
    }
}

void check_large_n_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: large_n_invariant triggered - large n with limited m causing inefficiency" << endl;
        abort();
    }
}

int main() {
    cin >> n >> m;

    // Insert check for large n with limited m
    check_large_n_invariant(n > 1e7 && m < 5);

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    // Insert sorting invariant check
    check_sorting_invariant(m > 10);

    // Sort matchboxes based on matches per box
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i] > b[j]) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
        }
    }

    // Insert selection invariant check
    check_selection_invariant(n > 1e7 && m > 5);

    for (int i = 0;; i++) {
        if (a[i] >= n) {
            ans += n * b[i];
            break;
        } else {
            ans += b[i] * a[i];
            n -= a[i];
        }
    }
    cout << ans;
}