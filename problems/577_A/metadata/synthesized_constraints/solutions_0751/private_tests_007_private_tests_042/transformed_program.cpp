#include <bits/stdc++.h>

void check_large_loop_invariant(int n) {
    if (n > 100000) {
        cerr << "Warning: Performance bottleneck due to large n value!" << endl;
        abort();
    }
}

void check_modulo_condition_invariant(int n, int x) {
    if (x < n / 10) {
        cerr << "Warning: Performance bottleneck due to small x value!" << endl;
        abort();
    }
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    // Check for potential performance bottlenecks
    check_large_loop_invariant(n);
    check_modulo_condition_invariant(n, x);

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int y = x / i;
        if ((x % i == 0) && (y <= n)) {
            cnt = cnt + 1;
        }
    }

    printf("%d\n", cnt);
    return 0;
}