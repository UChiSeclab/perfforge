#include <bits/stdc++.h>
using namespace std;

// Checker function to detect when n is much larger than m
void check_large_n_small_m_invariant(int n, int m) {
    if (m < 10 && n / m > 100000) { // Arbitrary threshold example
        cerr << "Warning: Performance bottleneck condition triggered - n much larger than m!" << endl;
        abort();
    }
}

// Checker function to detect large n with small m
void check_large_n_invariant(int n, int m) {
    if (n > 100000000 && m < 10) { // Threshold based on typical constraints
        cerr << "Warning: Performance bottleneck condition triggered - large n with small m!" << endl;
        abort();
    }
}

// Checker function to detect large n/m ratio
void check_large_n_m_ratio_invariant(int n, int m) {
    if (n / m > 100000) { // Example threshold for excessive loop iterations
        cerr << "Warning: Performance bottleneck condition triggered - large n/m ratio!" << endl;
        abort();
    }
}

int main() {
    int n, m, a, b, i = 1, j, t = 0, s = 0;
    int x[1000];
    cin >> n >> m >> a;

    // Perform invariant checks before the loop
    check_large_n_small_m_invariant(n, m);
    check_large_n_invariant(n, m);
    check_large_n_m_ratio_invariant(n, m);

    while (i * m <= n) i++;
    while (i * m + t <= a) {
        cout << i * m - n + t << " ";
        s = 1;
        t += m;
    }
    if (s == 0) cout << -1;
    return 0;
}