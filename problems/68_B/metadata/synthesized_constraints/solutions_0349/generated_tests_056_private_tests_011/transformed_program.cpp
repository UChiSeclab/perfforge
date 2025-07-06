#include <bits/stdc++.h>
using namespace std;

// Check functions based on performance invariants
void check_high_iterations(int n, int maxIterations) {
    if (n >= 8000 && maxIterations >= 10000) {
        cerr << "Warning: Performance bottleneck - high number of iterations for large n" << endl;
        abort();
    }
}

void check_large_inner_loop(int n) {
    if (n > 8000) {
        cerr << "Warning: Performance bottleneck - large number of accumulators in loop" << endl;
        abort();
    }
}

void check_energy_transfer_impact(int n, double p) {
    if (n > 8000 && p < 0.5) {
        cerr << "Warning: Performance bottleneck - significant energy adjustment needed" << endl;
        abort();
    }
}

int abs(int, int);
bool b(double, double, double[], int);
int fin(int[], int, int);

int main() {
    int n;
    double p;
    cin >> n >> p;
    p = 1 - p / 100;
    double a[10000];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // Insert checks after input reading
    check_high_iterations(n, 10000); // Check related to high number of binary search iterations
    check_large_inner_loop(n); // Check for large input size impacting loop performance
    check_energy_transfer_impact(n, p); // Check for significant energy adjustment

    double l = 0;
    double c;
    double h = 1000;
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
        } else
            a2 += x - a[i];
    }
    a1 = a1 * p;
    return (a1 >= a2);
}