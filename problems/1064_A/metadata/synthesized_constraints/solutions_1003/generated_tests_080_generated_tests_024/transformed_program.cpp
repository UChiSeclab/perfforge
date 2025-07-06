#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance-characterizing invariants
void check_close_sticks_invariant(int a, int b, int c) {
    if (std::max({a, b, c}) >= a + b + c - std::max({a, b, c})) {
        cerr << "Warning: Performance bottleneck condition triggered due to close stick lengths!" << endl;
        abort();
    }
}

void check_initial_imbalance_invariant(int a, int b, int c) {
    int max_length = std::max({a, b, c});
    int sum_others = a + b + c - max_length;
    if (max_length >= sum_others * 2) {
        cerr << "Warning: Performance bottleneck condition triggered due to initial imbalance!" << endl;
        abort();
    }
}

void check_near_limit_sticks_invariant(int a, int b, int c) {
    int min_length = std::min({a, b, c});
    int max_length = std::max({a, b, c});
    if (min_length == 1 && max_length > 50) { // Arbitrary threshold for demonstration
        cerr << "Warning: Performance bottleneck condition triggered due to near-limit sticks!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    // Insert invariant checks
    check_close_sticks_invariant(a, b, c);
    check_initial_imbalance_invariant(a, b, c);
    check_near_limit_sticks_invariant(a, b, c);

    int inf = 0x3f3f3f3f;
    int ans = inf;

    // Original code calculating the minimum number of minutes
    for (int i = a; i <= 100; i++) {
        for (int j = b; j <= 100; j++) {
            for (int k = c; k <= 100; k++) {
                if (i + j > k && i + k > j && j + k > i)
                    ans = min(ans, i - a + j - b + k - c);
            }
        }
    }

    cout << ans;
    return 0;
}