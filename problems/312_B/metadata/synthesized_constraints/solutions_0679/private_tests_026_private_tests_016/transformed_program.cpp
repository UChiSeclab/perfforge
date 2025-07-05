#include <bits/stdc++.h>
using namespace std;

// Checker for low probability invariant
void check_low_probability_invariant(double r, double o) {
    if (r < 0.01 && o < 0.01) {
        cerr << "Warning: Performance bottleneck condition triggered - low probability of hitting the target!" << endl;
        abort();
    }
}

// Checker for large denominator invariant
void check_large_denominator_invariant(double a, double b, double c, double d) {
    if ((b > 100 * a) || (d > 100 * c)) {
        cerr << "Warning: Performance bottleneck condition triggered - large denominators relative to numerators!" << endl;
        abort();
    }
}

int main() {
    long long i = 0;
    double a, b, c, d;
    double r, o, ans = 0;
    cin >> a >> b >> c >> d;

    // Calculate probabilities
    r = (a) / b;
    o = (c) / d;

    // Check for performance bottlenecks before entering the loop
    check_low_probability_invariant(r, o);
    check_large_denominator_invariant(a, b, c, d);

    // Main loop for probability calculation
    for (i = 0;; i++) {
        if ((pow((1 - r), i) * pow((1 - o), i)) < pow(10, -6))
            break;
        else
            ans += r * pow((1 - r), i) * pow((1 - o), i);
    }

    printf("%.12lf\n", ans);
    return 0;
}