#include <bits/stdc++.h>
using namespace std;

// Checker for invariant 1: Wide bid ranges
void check_wide_range_invariant(int l[], int r[], int n) {
    for (int i = 0; i < n; ++i) {
        if ((r[i] - l[i]) > 5000) { // Arbitrary threshold for "wide" range
            cerr << "Warning: Performance bottleneck condition triggered due to wide bid range!" << endl;
            abort();
        }
    }
}

// Checker for invariant 2: Overlapping bid ranges
void check_overlap_invariant(int l[], int r[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (max(l[i], l[j]) <= min(r[i], r[j])) { // Overlapping range condition
                cerr << "Warning: Performance bottleneck condition triggered due to overlapping bid ranges!" << endl;
                abort();
            }
        }
    }
}

int l[8], r[8];
int n;

double dfs(int x, int dep, int cnt1, int cnt2, double p) {
    if (dep == n) {
        if (cnt1 + cnt2 >= 2 && cnt2 <= 1) {
            return p * x;
        } else
            return 0;
    }
    if (x < l[dep]) {
        return dfs(x, dep + 1, cnt1, cnt2 + 1, p);
    } else if (l[dep] <= x && x <= r[dep]) {
        double tp = 0;
        tp += dfs(x, dep + 1, cnt1, cnt2, p * (x - l[dep]) / (r[dep] - l[dep] + 1));
        tp += dfs(x, dep + 1, cnt1 + 1, cnt2, p * 1 / (r[dep] - l[dep] + 1));
        tp += dfs(x, dep + 1, cnt1, cnt2 + 1,
                  p * (r[dep] - x) / (r[dep] - l[dep] + 1));
        return tp;
    } else {
        return dfs(x, dep + 1, cnt1, cnt2, p);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", l + i, r + i);

    // Insert checks after reading input
    check_wide_range_invariant(l, r, n);
    check_overlap_invariant(l, r, n);

    double res = 0;
    for (int i = 1; i <= 10000; i++) {
        res += dfs(i, 0, 0, 0, 1.0);
    }
    printf("%.10f\n", res);
    return 0;
}