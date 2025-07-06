#include <bits/stdc++.h>
using namespace std;
long long n;

void check_large_target_invariant(long long n, long long m) {
    if (m > n * 10000) {
        cerr << "Warning: large_target_invariant triggered - excessive potential recursion depth" << endl;
        abort();
    }
}

void check_invalid_path_invariant(long long n, long long m) {
    long long original_m = m;
    while (m % 2 == 0) m /= 2;
    while (m % 3 == 0) m /= 3;
    if (m != 1) {
        cerr << "Warning: invalid_path_invariant triggered - m contains non-2,3 factors" << endl;
        abort();
    }
    m = original_m;
}

void check_exponential_growth_invariant(long long n, long long m) {
    int count_powers = 0;
    while (m % 2 == 0) {
        m /= 2;
        count_powers++;
    }
    while (m % 3 == 0) {
        m /= 3;
        count_powers++;
    }
    if (count_powers > 50) {
        cerr << "Warning: exponential_growth_invariant triggered - large number of state expansions" << endl;
        abort();
    }
}

void sero(long long x, int i) {
    if (x > n) return;
    if (x == n) {
        cout << i;
        exit(0);
    }
    sero(x * 2, i + 1);
    sero(x * 3, i + 1);
}

int main() {
    int x;
    cin >> x >> n;

    // Insert checks after reading inputs but before recursion starts
    check_large_target_invariant(x, n);
    check_invalid_path_invariant(x, n);
    check_exponential_growth_invariant(x, n);

    sero(x, 0);
    cout << "-1";
    return 0;
}