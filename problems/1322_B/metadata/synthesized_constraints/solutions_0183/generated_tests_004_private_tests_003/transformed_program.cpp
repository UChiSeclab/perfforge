#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
int a[maxn], b[maxn];

void check_sorting_invariant(int n) {
    if (n > 75) {
        cerr << "Warning: Performance bottleneck condition triggered - sorting and nested loop operations." << endl;
        abort();
    }
}

void check_lower_bound_invariant(int n) {
    if (n > 75) {
        cerr << "Warning: Performance bottleneck condition triggered - intensive lower bound searches." << endl;
        abort();
    }
}

void check_nested_operations_invariant(int n) {
    if (n > 75) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive bitwise operations in nested loops." << endl;
        abort();
    }
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    // Check for potential performance bottlenecks
    check_sorting_invariant(n);
    check_lower_bound_invariant(n);
    check_nested_operations_invariant(n);

    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < 30; i++) {
        int mod = 1 << (1 + i);
        for (int j = 1; j <= n; j++) b[j] = a[j] % mod;
        sort(b + 1, b + n + 1);
        int res = 0;
        for (int j = 1; j <= n; j++) {
            int l, r;
            l = lower_bound(b + 1, b + n + 1, (1 << i) - b[j]) - b;
            r = lower_bound(b + 1, b + n + 1, (1 << (i + 1)) - b[j]) - b - 1;
            res += r - l + 1;
            l = lower_bound(b + 1, b + n + 1, (1 << (i + 1)) + (1 << i) - b[j]) - b;
            r = lower_bound(b + 1, b + n + 1, (1 << (i + 2)) - b[j]) - b - 1;
            res += r - l + 1;
            if ((b[j] + b[j]) & (1 << i)) res--;
        }
        if ((res >> 1) & 1) ans += (1 << i);
    }
    printf("%d\n", ans);
    return 0;
}