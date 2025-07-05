#include <bits/stdc++.h>
using namespace std;

bool b(double, double, double[], int);

// Checker function to detect potential performance bottlenecks
void check_accumulator_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: accumulator_invariant triggered - excessive loop iterations due to high n" << endl;
        abort();
    }
}

int main() {
    int n;
    double p;
    cin >> n >> p;

    // Insert the check after reading input values
    check_accumulator_invariant(n > 5000); // Assumes large n leads to slowdown

    p = 1 - p / 100;
    double a[10000];
    for (int i = 0; i < n; i++) cin >> a[i];
    double l = 0;
    double c;
    double h = 10000000;
    for (int i = 0; i < 10000; i++) {
        c = (l + h) / 2;
        if (b(c, p, a, n))
            l = c;
        else
            h = c;
    }
    printf("%.6f", (l + h) / 2);
    return 0;
}

bool b(double x, double p, double a[], int n) {
    double a1 = 0;
    double a2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= x) {
            a1 += a[i] - x;
        } else {
            a2 += x - a[i];
        }
    }
    a1 = a1 * p;
    return (a1 >= a2);
}