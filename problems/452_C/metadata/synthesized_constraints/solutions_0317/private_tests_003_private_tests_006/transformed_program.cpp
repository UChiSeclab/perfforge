#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:36777216")
using namespace std;
const int N = 30005;
const long long INF = 0x3fffffffffffffffLL;
const int MOD = 1e9 + 7;
const long double EPS = 1e-8;

// Checker function for large iterations in nested loop
void check_large_iteration_invariant(int n, int m) {
    if (n > 900 && m > 900) {
        cerr << "Warning: Performance bottleneck condition triggered - large iterations in nested loops!" << endl;
        abort();
    }
}

// Checker function for expensive combinatorial calculations
void check_expensive_calculations_invariant(int n, int m) {
    if (n > 900 && m > 900) {
        cerr << "Warning: Performance bottleneck condition triggered - expensive combinatorial calculations!" << endl;
        abort();
    }
}

long double C(int x, int y) {
    long double res = 0.0;
    for (int i = x - y + 1; i <= x; i++) res += log((long double)i);
    for (int i = 1; i <= y; i++) res -= log((long double)i);
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Insert checkers to detect performance bottlenecks
    check_large_iteration_invariant(n, m);
    check_expensive_calculations_invariant(n, m);

    long double ans = 0.0;
    for (int i = 1; i <= min(n, m); i++) {
        long double k = C(m, i) + C(n * m - m, n - i) - C(n * m, n);
        k += 2 * log((long double)i);
        k -= 2 * log((long double)n);
        ans += exp(k);
    }
    cout << setprecision(20) << ans * n << endl;
}