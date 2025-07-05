#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance bottlenecks
void check_high_iteration_invariant(int n, int m) {
    if (n > 900 && m > 900) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count in nested loops!" << endl;
        abort();
    }
}

void check_exponential_growth_invariant(int n, int m) {
    if (n > 900 && m > 900) {
        cerr << "Warning: Performance bottleneck condition triggered - exponential growth due to nested function calls!" << endl;
        abort();
    }
}

void check_logarithmic_calculation_invariant(int n, int m) {
    if (n > 900 && m > 900) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient logarithmic calculations!" << endl;
        abort();
    }
}

void check_combination_complexity_invariant(int n, int m) {
    if (n > 900 && m > 900) {
        cerr << "Warning: Performance bottleneck condition triggered - complexity in combining inputs for computation!" << endl;
        abort();
    }
}

// Original solution code
double cr(int n, int m) {
    double res = 0;
    for (int i = 1; i < m + 1; i++) {
        res += -log(i) + log(n - i + 1);
    }
    return res;
}

int main() {
    int n, m;
    while (cin >> n >> m) {

        // Insert checker functions after reading inputs
        check_high_iteration_invariant(n, m);
        check_exponential_growth_invariant(n, m);
        check_logarithmic_calculation_invariant(n, m);
        check_combination_complexity_invariant(n, m);

        int mi = min(n, m);
        double ans = 0;
        for (int i = 1; i < mi + 1; i++) {
            double tem = 2 * (log(i) - log(n)) + log(n) + cr(m, i) +
                         cr((n - 1) * m, n - i) - cr(n * m, n);
            ans += exp(tem);
        }
        printf("%.9f\n", ans);
    }
    return 0;
}