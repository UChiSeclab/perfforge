#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_loop_iteration_invariant(double m) {
    if (m > 900) { // Threshold chosen as a heuristic when m is large.
        cerr << "Warning: High loop iteration invariant triggered - m is large, causing extensive loop iterations." << endl;
        abort();
    }
}

void check_expensive_calculations_invariant(double n, double m) {
    if (m * n > 950000) { // Condition indicating potentially expensive calculations.
        cerr << "Warning: Expensive calculations invariant triggered - m and n combination may lead to heavy computation." << endl;
        abort();
    }
}

void check_function_call_overhead_invariant(double a, double m) {
    if (a > m * 0.9) { // If a approaches m, indicating repeated computation.
        cerr << "Warning: Function call overhead invariant triggered - repeated calls with large parameters." << endl;
        abort();
    }
}

// Probability calculation function
double pr(double a, double n, double m) {
    check_function_call_overhead_invariant(a, m); // Insert check before loop processing
    double u = 1.0;
    for (int i = 0; i < a; i++) u *= (m - i) / (m * n - i);
    for (int i = 0; i < n - a; i++) u *= (m * n - m - i) / (m * n - a - i);
    for (int i = 0; i < a; i++) {
        u *= (n - i) / (a - i);
    }
    return u;
}

int main() {
    double n;
    double m;
    cin >> n >> m;

    // Insert checks after input and before main computation
    check_high_loop_iteration_invariant(m);
    check_expensive_calculations_invariant(n, m);

    double p = 0;
    for (double i = 1; i <= m; i++) {
        p += i * i / n * pr(i, n, m);
    }
    cout << p;
    return 0;
}