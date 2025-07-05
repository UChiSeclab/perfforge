#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;

void check_probability_ratio_invariant(double a, double b, double c, double d) {
    if ((a/b < 0.01 && c/d < 0.01) || (a/b > 0.99 && c/d > 0.99)) {
        cerr << "Warning: Probability ratio invariant triggered - potential for excessive iterations!" << endl;
        abort();
    }
}

void check_small_probability_invariant(double a, double b, double c, double d) {
    if ((a/b < 0.01 && 1.0 - c/d < 0.01) || (c/d < 0.01 && 1.0 - a/b < 0.01)) {
        cerr << "Warning: Small probability invariant triggered - slow convergence expected!" << endl;
        abort();
    }
}

void check_precision_threshold_invariant(double a, double b, double c, double d) {
    if ((a/b < 0.01 && c/d < 0.01) && (abs(a/b - c/d) < 1e-6)) {
        cerr << "Warning: Precision threshold invariant triggered - minute changes causing slow execution!" << endl;
        abort();
    }
}

int main() {
    cin >> a >> b >> c >> d;

    // Check for performance bottlenecks before entering the loop
    check_probability_ratio_invariant(a, b, c, d);
    check_small_probability_invariant(a, b, c, d);
    check_precision_threshold_invariant(a, b, c, d);

    double res = 0.0;
    double lst = 2.0;
    int i = 0;

    while (!(abs(lst - res) < 1e-12)) {
        lst = res;
        res += pow(1.0 - (a / b), i) * (a / b) * pow(1.0 - (c / d), i);
        i++;
    }

    printf("%.12f\n", res);
    return 0;
}