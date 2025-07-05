#include <bits/stdc++.h>
using namespace std;
const int MAX_N = (1 << 18);
int n, m;
int ans = 0;

// Checker functions
void check_large_ratio_invariant(int n, int m) {
    if ((m % n) != 0) {
        cerr << "Warning: Performance bottleneck condition triggered - large disparity between n and m without direct factorization by 2 and 3!" << endl;
        abort();
    }
}

void check_factor_invariant(int m) {
    int temp = m;
    while (temp % 2 == 0) temp /= 2;
    while (temp % 3 == 0) temp /= 3;
    if (temp != 1) {
        cerr << "Warning: Performance bottleneck condition triggered - m has factors other than 2 and 3 leading to complex recursion!" << endl;
        abort();
    }
}

void check_complex_factorization(int n, int m) {
    int factorProduct = m / n;
    while (factorProduct % 2 == 0) factorProduct /= 2;
    while (factorProduct % 3 == 0) factorProduct /= 3;
    if (factorProduct != 1) {
        cerr << "Warning: Performance bottleneck condition triggered - complex factorization path!" << endl;
        abort();
    }
}

void check_multiplicative_path(int n, int m) {
    int ratio = m / n;
    if (ratio > 1000) { // Arbitrary large threshold to demonstrate concept
        cerr << "Warning: Performance bottleneck condition triggered - large ineffective multiplicative path!" << endl;
        abort();
    }
}

bool func(int crt, int cnt) {
    if (crt > m)
        return 0;
    else if (crt == m) {
        ans = cnt;
        return 1;
    }
    return func(crt * 3, cnt + 1) | func(crt * 2, cnt + 1);
}

int main() {
    cin >> n >> m;

    // Insert checker functions here to catch bottlenecks
    check_large_ratio_invariant(n, m);
    check_factor_invariant(m);
    check_complex_factorization(n, m);
    check_multiplicative_path(n, m);

    if (!func(n, 0)) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}