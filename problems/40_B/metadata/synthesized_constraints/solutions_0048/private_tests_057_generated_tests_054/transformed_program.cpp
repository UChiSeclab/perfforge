#include <bits/stdc++.h>
using namespace std;

// Checkers for performance bottlenecks
void check_large_m_invariant(long long m, long long x) {
    if (m - 2 * x + 1 > 1000) {
        cerr << "Warning: Performance bottleneck - large range for inner loop due to m" << endl;
        abort();
    }
}

void check_small_x_invariant(long long n, long long m, long long x) {
    if (x < n / 10 && m > 1000) {
        cerr << "Warning: Performance bottleneck - small x relative to large m" << endl;
        abort();
    }
}

void check_even_matching_condition(long long m) {
    if (m > 1000) {
        cerr << "Warning: Performance bottleneck - high matches for even-index condition" << endl;
        abort();
    }
}

int main() {
    long long n, m, x, s = 0;
    cin >> n >> m >> x;

    // Insert performance checks before heavy computations
    check_large_m_invariant(m, x);
    check_small_x_invariant(n, m, x);
    check_even_matching_condition(m);

    for (long long i = x; i <= n - x + 1; i++) {
        for (long long j = x; j <= m - x + 1; j++) {
            if (i % 2 == j % 2)
                if (min(min(i, j), min(n - i + 1, m - j + 1)) == x) ++s;
        }
    }
    cout << s;
    return 0;
}