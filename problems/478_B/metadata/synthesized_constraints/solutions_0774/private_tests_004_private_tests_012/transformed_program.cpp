#include <bits/stdc++.h>
using namespace std;

long long int C(long long int n, long long int r);

void check_high_iteration_invariant(long long rem, long long m) {
    if (rem >= 100000000 && m == 1) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration in loop." << endl;
        abort();
    }
}

void check_small_team_invariant(long long n, long long m) {
    if (m == 1 && n > 100000000) {
        cerr << "Warning: Performance bottleneck condition triggered - small team size effect." << endl;
        abort();
    }
}

void check_arithmetic_operation_invariant(long long rem, long long m) {
    if ((rem / m) > 100000000) {
        cerr << "Warning: Performance bottleneck condition triggered - arithmetic operation overhead." << endl;
        abort();
    }
}

int main() {
    long long int n, m;
    cin >> n >> m;

    // Check for invariants before entering critical computations
    check_small_team_invariant(n, m);

    long long int kmin = 0, kmax = 0;
    long long int rem = n - m;

    // Check for high iteration loop invariant
    check_high_iteration_invariant(rem, m);

    kmax = (m == n ? 0 : C(rem + 1, 2));

    long long int nmin = 1;
    while (rem >= m) {
        rem -= m;
        nmin++;
    }

    // Check for arithmetic operation overhead invariant
    check_arithmetic_operation_invariant(rem, m);

    kmin = (rem) * C(nmin + 1, 2) + (m - rem) * C(nmin, 2);

    cout << kmin << " " << kmax << '\n';
    return 0;
}

long long int C(long long int n, long long int r) {
    long long int num = 1, den = 1;
    while (r) {
        num *= n - r + 1;
        den *= r;
        r--;
    }
    return num / den;
}