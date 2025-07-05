#include <bits/stdc++.h>
using namespace std;

// Define checkers for performance bottlenecks
void check_loop_complexity(long n) {
    if (n > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - large n causing high loop iterations!" << endl;
        abort();
    }
}

void check_divisibility(long long x) {
    if (x < 10) {
        cerr << "Warning: Performance bottleneck condition triggered - small x leading to frequent divisibility checks!" << endl;
        abort();
    }
}

void check_operation_count(long n, long long x) {
    if (n > 10000 && x < 10) {
        cerr << "Warning: Performance bottleneck condition triggered - large n and small x causing excessive operations!" << endl;
        abort();
    }
}

int main() {
    long t = 0, n, i;
    long long x;
    cin >> n >> x;

    // Insert checks to detect performance bottlenecks
    check_loop_complexity(n);
    check_divisibility(x);
    check_operation_count(n, x);

    for (i = 1; i <= n; i++) {
        if ((x / i == (x * 1.00 / i)) && ((x / i) <= n)) t++;
    }
    cout << t;
}