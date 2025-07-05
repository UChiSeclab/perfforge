#include <bits/stdc++.h>
using namespace std;
const long long P = 1e8;
long long n, p;

long long deg(long long k) {
    long long a = 0;
    while (k > 0) {
        a += k % 2;
        k /= 2;
    }
    return a;
}

// Checker functions for performance bottlenecks
void check_negative_or_small_solutions(long long k, long long i) {
    if (k <= 0 || k < i) {
        cerr << "Warning: Performance bottleneck condition triggered - negative or small k." << endl;
        abort();
    }
}

void check_inefficient_loop_termination(long long n, long long p, long long i) {
    long long k = n - i * p;
    if (k > 0 && k < i && i > 1e7) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient loop termination." << endl;
        abort();
    }
}

void check_missed_early_termination(long long k, long long i) {
    if ((k <= 0 || k < i) && i > 1e7) {
        cerr << "Warning: Performance bottleneck condition triggered - missed early termination." << endl;
        abort();
    }
}

int main() {
    cin >> n >> p;
    long long ans = -1;
    for (long long i = 1; i <= P; i++) {
        long long k = n - i * p;

        // Insert invariant checks
        check_negative_or_small_solutions(k, i);
        check_inefficient_loop_termination(n, p, i);
        check_missed_early_termination(k, i);

        if (k <= 0 || k < i) {
            continue;
        }
        long long cnt = deg(k);
        if (cnt <= i) {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}