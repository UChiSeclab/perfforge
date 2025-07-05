#include <bits/stdc++.h>
using namespace std;

// Checker function for high number of departments
void check_high_departments_invariant(int m) {
    if (m > 500) { // Arbitrary threshold considering m's upper limit is 1000
        cerr << "Warning: Performance bottleneck condition triggered - too many departments!" << endl;
        abort();
    }
}

// Checker function for large team size
void check_large_team_size_invariant(int n) {
    if (n > 50) { // Threshold close to n's upper limit
        cerr << "Warning: Performance bottleneck condition triggered - large team size leading to expensive nested loops!" << endl;
        abort();
    }
}

// Checker function for high repeated operations
void check_repeated_operations_invariant(double s, double a_h) {
    if (s - a_h > 70) { // Threshold to determine repeated operations becoming costly
        cerr << "Warning: Performance bottleneck condition triggered - high repeated operations in calculation!" << endl;
        abort();
    }
}

int main() {
    double n;
    int m;
    int h;
    cin >> n;
    cin >> m;
    cin >> h;

    // Check for high number of departments
    check_high_departments_invariant(m);

    double a[m];
    double s = 0;
    n--;
    h--;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        s += a[i];
    }
    a[h]--;
    s--;

    // Check for repeated operations in calculation
    check_repeated_operations_invariant(s, a[h]);

    if (s < n) {
        cout << -1.0 << endl;
        return 0;
    }
    if (s == n && a[h] != 0) {
        cout << 1.0 << endl;
        return 0;
    }
    if (a[h] == 0) {
        cout << 0.0 << endl;
        return 0;
    }
    if (s - a[h] < n) {
        cout << 1.0 << endl;
        return 0;
    }
    s = s - a[h];
    double res = 0;
    double r;
    int f = 0;

    // Check for large team size
    check_large_team_size_invariant(static_cast<int>(n) + 1);

    while (n) {
        if (f == 0) {
            res = (double)(a[h] / (s + a[h]));
        } else {
            r = (a[h] / ((s - f) + a[h]));
            for (int i = 0; i < f; i++) r *= (s - i) / (s + a[h] - i);
            res += r;
        }
        n--;
        f++;
    }
    cout << res << endl;
    return 0;
}