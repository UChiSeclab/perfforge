#include <bits/stdc++.h>
using namespace std;

// Checkers for performance invariants
void check_large_range_small_step_invariant(int y, int m, int n) {
    if ((n - y) / m > 100000) {
        cerr << "Warning: large_range_small_step_invariant triggered - excessive loop iterations" << endl;
        abort();
    }
}

void check_small_m_invariant(int y, int m, int n) {
    if (m < 10 && n > 100000 && y > 100000) {
        cerr << "Warning: small_m_invariant triggered - m is very small compared to n and y" << endl;
        abort();
    }
}

void check_large_diff_invariant(int y, int m, int n) {
    if ((n - y) - (m - y) > 1000000) {
        cerr << "Warning: large_diff_invariant triggered - large loop range" << endl;
        abort();
    }
}

int main() {
    int y, m, n;
    cin >> y >> m >> n;

    // Insert checks after input to catch problematic configurations early
    check_large_range_small_step_invariant(y, m, n);
    check_small_m_invariant(y, m, n);
    check_large_diff_invariant(y, m, n);

    vector<int> a;
    for (int i = m - y; i <= n - y; i += m) {
        if ((i + y) % m == 0 && i > 0) {
            a.push_back(i);
        }
    }

    if (a.empty()) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
    }
}