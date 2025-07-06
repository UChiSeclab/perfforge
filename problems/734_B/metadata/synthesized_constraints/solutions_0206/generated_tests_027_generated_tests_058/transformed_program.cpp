#include <bits/stdc++.h>
using namespace std;

// Checkers for performance bottlenecks
void check_loop_iteration_invariant(int k2, int k5, int k6) {
    if (k2 > 2 * std::min(k5, k6)) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive loop iterations!" << endl;
        abort();
    }
}

void check_resource_limitation_invariant(int k2, int k5, int k6) {
    if (k2 > std::min(k5, k6)) {
        cerr << "Warning: Performance bottleneck condition triggered due to resource limitation!" << endl;
        abort();
    }
}

void check_input_balance_invariant(int k2, int k5, int k6) {
    if (abs(k2 - k5) > k5 / 2 || abs(k2 - k6) > k6 / 2) {
        cerr << "Warning: Performance bottleneck condition triggered due to unbalanced input!" << endl;
        abort();
    }
}

const int maxn = 1e6 + 100;
int val[maxn];
long long res = 0;

int main() {
    ios::sync_with_stdio(false);
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;

    // Insert check for performance bottlenecks after reading inputs
    check_loop_iteration_invariant(k2, k5, k6);
    check_resource_limitation_invariant(k2, k5, k6);
    check_input_balance_invariant(k2, k5, k6);

    for (int i = 0; i <= k2; i++) {
        if (i <= k2 and i <= k5 and i <= k6) {
            long long sum = i * 256;
            sum += min(k3, k2 - i) * 32;
            res = max(res, sum);
        }
    }
    cout << res;
}