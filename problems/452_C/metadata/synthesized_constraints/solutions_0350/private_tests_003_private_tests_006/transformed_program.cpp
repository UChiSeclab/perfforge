#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const long long linf = 1e18 + 5;
int n, m;
double ans;

void check_large_combination(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to large combinatorics calculation!" << endl;
        abort();
    }
}

void check_extensive_loop_iterations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to extensive loop iterations!" << endl;
        abort();
    }
}

void check_expensive_function_calls(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to repeated expensive function calls!" << endl;
        abort();
    }
}

double logC(int n, int r) {
    double ans = 0;
    for (int i = 1; i <= r; i++) ans += log(n - i + 1);
    for (int i = 1; i <= r; i++) ans -= log(i);
    return ans;
}

double calc(int k) {
    return logC((n - 1) * m, (n - k)) + logC(m, k) + log(k) * 2 - log(n) * 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    
    // Check for large combinatorics calculation
    check_large_combination(n > 900 && m > 900);

    // Check for extensive loop iterations
    check_extensive_loop_iterations(min(n, m) > 900);

    double mul = log(n) - logC(n * m, n);

    // Check before entering the loop to prevent excessive function calls
    check_expensive_function_calls(min(n, m) > 900);

    for (int i = 1; i <= min(n, m); i++) ans += exp(calc(i) + mul);

    cout << fixed << setprecision(12) << ans << '\n';
    return 0;
}