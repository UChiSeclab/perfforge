#include <bits/stdc++.h>
using namespace std;

void check_balanced_stick_lengths_invariant(int a, int b, int c) {
    if (abs(a - b) <= 1 && abs(b - c) <= 1 && abs(c - a) <= 1 && a > 90 && b > 90 && c > 90) {
        cerr << "Warning: Performance bottleneck condition triggered - nearly equal large stick lengths!" << endl;
        abort();
    }
}

void check_large_iteration_space_invariant(int a, int b, int c) {
    if (a > 90 && b > 90 && c > 90) {
        cerr << "Warning: Performance bottleneck condition triggered - large iteration space due to high stick lengths!" << endl;
        abort();
    }
}

void check_initial_imbalance_invariant(int a, int b, int c) {
    int maxLength = max({a, b, c});
    int minLength = min({a, b, c});
    if (maxLength - minLength >= 99) {
        cerr << "Warning: Performance bottleneck condition triggered - significant initial length disparity!" << endl;
        abort();
    }
}

int solve() {
    int a, b, c;
    scanf("%d%d%d", &a, &c, &b);

    // Check performance invariants after reading inputs
    check_balanced_stick_lengths_invariant(a, b, c);
    check_large_iteration_space_invariant(a, b, c);
    check_initial_imbalance_invariant(a, b, c);

    int ans = 1000000009;
    for (int i = 0; i < 256; ++i)
        for (int j = 0; j < 256; ++j)
            for (int k = 0; k < 256; ++k) {
                if ((a + i) < (b + j) + (c + k) && (b + j) < (a + i) + (c + k) &&
                    (c + k) < (a + i) + (b + j)) {
                    ans = std::min(ans, i + j + k);
                }
            }
    printf("%d\n", ans);
    return 0;
}

int main() {
    ::std::ios::sync_with_stdio(false);
    ::std::cin.tie(0);
    ::std::cout.tie(0);
    int t = 1;
    while (t--) solve();
}