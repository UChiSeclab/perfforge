#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_exhaustive_iteration_invariant(long long a, long long b, long long c, long long d) {
    if ((b - d) % std::gcd(a, c) != 0) {
        cerr << "Warning: Performance bottleneck condition triggered - exhaustive loop iteration!" << endl;
        abort();
    }
}

void check_symmetrical_sequences_invariant(long long a, long long b, long long c, long long d) {
    if (a == c && (b % a != d % a)) {
        cerr << "Warning: Performance bottleneck condition triggered - symmetrical sequences non-intersecting!" << endl;
        abort();
    }
}

void check_large_step_sizes_invariant(long long a, long long b, long long c, long long d) {
    if ((a > 50 || c > 50) && (b - d) % std::gcd(a, c) != 0) {
        cerr << "Warning: Performance bottleneck condition triggered - large step sizes with no intersection!" << endl;
        abort();
    }
}

int main() {
    long long a, b;
    cin >> a >> b;
    long long c, d;
    cin >> c >> d;

    // Insert checks after reading inputs
    check_exhaustive_iteration_invariant(a, b, c, d);
    check_symmetrical_sequences_invariant(a, b, c, d);
    check_large_step_sizes_invariant(a, b, c, d);

    for (long long i = 0; i <= 1e4; i++) {
        for (long long j = 0; j <= 1e4; j++) {
            if (b + a * i == d + c * j) {
                cout << b + a * i << "\n";
                return 0;
            }
        }
    }
    cout << -1 << "\n";
}