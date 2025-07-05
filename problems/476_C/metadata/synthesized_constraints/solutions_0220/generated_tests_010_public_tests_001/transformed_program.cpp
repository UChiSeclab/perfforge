#include <bits/stdc++.h>
using namespace std;

void check_loop_size_invariant(long long int b) {
    if (b > 1000000) {  // Assume a threshold to detect when b is too large
        cerr << "Warning: Performance bottleneck condition triggered due to large loop size!" << endl;
        abort();
    }
}

void check_computational_overhead_invariant(long long int iterations) {
    if (iterations > 1000000) {  // Arbitrary large threshold to detect excessive computations
        cerr << "Warning: Computational overhead invariant triggered due to excessive operations!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    long long int a, b;
    cin >> a >> b;

    // Check for potential performance bottlenecks
    check_loop_size_invariant(b);

    long long int an = 0;
    for (int i = 1; i < b; ++i) {
        // Check computational overhead within the loop
        if (i % 1000000 == 0) {
            check_computational_overhead_invariant(i);
        }

        long long int d = i * a;
        long long int r = d / i;
        an += r * i;
        an %= 1000000007;
        long long int e = (r * (r + 1)) / 2;
        e %= 1000000007;
        e *= i;
        e %= 1000000007;
        e *= b;
        e %= 1000000007;
        an += e;
        an %= 1000000007;
    }
    cout << an;
}