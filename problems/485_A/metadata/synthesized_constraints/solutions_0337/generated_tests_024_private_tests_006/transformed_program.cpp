#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
long long a, m;

void check_stuck_loop_invariant(long long a, long long m, int sum) {
    if (sum > 1e7 && a % m != 0) {
        cerr << "Warning: Performance bottleneck condition triggered - stuck in loop without reaching divisible condition!" << endl;
        abort();
    }
}

void check_iteration_limit_invariant(int sum) {
    if (sum > 1e7) {
        cerr << "Warning: Performance bottleneck condition triggered - iteration limit reached without result!" << endl;
        abort();
    }
}

int main() {
    scanf("%lld%lld", &a, &m);
    int sum = 0;

    while (sum <= 1e7) {
        if (a % m == 0) return 0 * puts("Yes");
        a = a + a % m;
        sum++;

        // Integrate invariant checks
        check_stuck_loop_invariant(a, m, sum); // Check if stuck in loop
        check_iteration_limit_invariant(sum);  // Check iteration limit
    }
    puts("No");
}