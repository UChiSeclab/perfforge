#include <bits/stdc++.h>
using namespace std;

// Check for large range between smallest and largest elements
void check_large_range_invariant(int min, int max) {
    if ((max - min) > 100000) { // Example threshold to detect large range
        cerr << "Warning: Performance bottleneck condition triggered due to large range between smallest and largest elements!" << endl;
        abort();
    }
}

// Check for large values in piles
void check_large_values_invariant(int max_val) {
    if (max_val > 1000000) { // Example threshold for large values
        cerr << "Warning: Performance bottleneck condition triggered due to large values in the piles!" << endl;
        abort();
    }
}

int main() {
    int n, a[200010], b[200010];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(&a[1], &a[n + 1]);

    int min = (int)sqrt(a[1]);
    int max = (int)sqrt(a[n]);

    // Insert check to catch large range between smallest and largest elements
    check_large_range_invariant(min, max);

    // Insert check to detect large values in pile
    check_large_values_invariant(a[n]);

    int l = 1;
    for (int i = min; i <= max + 1; i++) {
        int x = i * i;
        while (a[l] <= x) {
            b[l] = x - a[l];
            l++;
            if (l == n + 1) break;
        }
        if (l == n + 1) break;
    }

    l = n;
    for (int i = max; i >= min; i--) {
        int x = i * i, y;
        while (a[l] >= x) {
            y = a[l] - x;
            if (y < b[l]) b[l] = y;
            l--;
            if (!l) break;
        }
        if (!l) break;
    }

    sort(&b[1], &b[n + 1]);
    long long ans = 0;
    int st = n / 2 + 1;
    for (; st <= n; st++) {
        if (b[st])
            break;
        else {
            if (!a[st])
                ans += 2;
            else
                ans += 1;
        }
    }
    n /= 2;
    for (int i = 1; i <= n; i++) ans += b[i];
    printf("%lld\n", ans);
    return 0;
}