#include <bits/stdc++.h>
using namespace std;

// Function to calculate combinations
long double C(int n, int r) {
    long double res = 1;
    for (int i = 1; i <= r; i++) res /= i;
    for (int i = n - r + 1; i <= n; i++) res *= i;
    return res;
}

// Checker functions for performance invariants
void check_high_combination_count(int s_h, int n) {
    if (s_h >= n - 1) {
        cerr << "Warning: Performance bottleneck condition triggered - High combination count due to large s[h]." << endl;
        abort();
    }
}

void check_loop_execution_overhead(int s_h, int n) {
    if (s_h > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - Loop executes excessively due to large s[h]." << endl;
        abort();
    }
}

void check_combination_function_complexity(int s_h, int n) {
    if (s_h > n * 0.75) {
        cerr << "Warning: Performance bottleneck condition triggered - Expensive combination calculations due to large s[h]." << endl;
        abort();
    }
}

int main() {
    int n, m, h;
    cin >> n >> m >> h;
    int s[m + 1];
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        cin >> s[i];
        sum += s[i];
    }

    // Run performance checkers after reading input
    check_high_combination_count(s[h], n);
    check_loop_execution_overhead(s[h], n);
    check_combination_function_complexity(s[h], n);

    if (sum < n)
        cout << -1;
    else {
        cout << setprecision(7);
        cout << showpoint;
        long double a = 0;
        for (int i = 1; i <= s[h] - 1; i++) {
            if (i > (n - 1)) break;
            a = a + C(s[h] - 1, i) * C(sum - s[h], n - i - 1);
        }
        long double b = C(sum - s[h], n - 1);
        if (sum - s[h] < n - 1) b = 0;
        double res = (a * 1.0) / (a + b);
        cout << res;
    }
}