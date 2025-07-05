#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int inf = 2147483647;
const int maxn = 10000;
int n, a, b, c;
int ans;

// Checkers for performance bottlenecks
void check_high_iteration_count_invariant(int b, int c) {
    if (c > 2500 && b > 2500) { // Check for large values that could cause excessive loop iterations
        cerr << "Warning: Performance bottleneck due to high iteration count in nested loops!" << endl;
        abort();
    }
}

void check_excessive_combinations_invariant(int a, int b, int c) {
    if (b > 4500 && a == 0 && c > 2500) { // When 1-liter bottles are high, and no 0.5-liter bottles are available
        cerr << "Warning: Performance bottleneck due to excessive combinations of 1-liter bottles!" << endl;
        abort();
    }
}

void check_minimal_half_liter_bottles_invariant(int a, int b, int c) {
    if (a == 0 && b > 4500 && c > 2500) { // No 0.5-liter bottles with high counts of 1 and 2-liter bottles
        cerr << "Warning: Performance bottleneck due to minimal use of 0.5-liter bottles!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d%d%d", &n, &a, &b, &c);

    // Integrate performance checkers
    check_high_iteration_count_invariant(b, c);
    check_excessive_combinations_invariant(a, b, c);
    check_minimal_half_liter_bottles_invariant(a, b, c);

    int d = a / 2;
    for (int i = 0; i <= c && n - 2 * i >= 0; i++) {
        int res = n - 2 * i;
        if (d + b < res) continue;
        for (int j = 0; j <= b; j++) {
            int rr = res - j;
            if (rr <= d && rr >= 0) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}