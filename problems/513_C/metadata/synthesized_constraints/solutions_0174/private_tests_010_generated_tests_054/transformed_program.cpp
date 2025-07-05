#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9, maxn = (int)1e5 + 1;
const double eps = (double)1e-8;
const int mod = (int)1000000009;
int i, n, l[10], r[10];
double s, v, ans;

// Check for high overlapping bid ranges
void check_range_overlap_invariant(int n, int l[], int r[]) {
    int overlapCount = 0;
    for (int i = 1; i <= n; ++i) {
        if (r[i] > 9000) {  // Consider ranges that extend high near max value
            overlapCount++;
        }
    }
    if (overlapCount > 1) {  // More than one company has a high overlapping range
        cerr << "Warning: Performance bottleneck due to high overlapping bid ranges!" << endl;
        abort();
    }
}

// Check for high branching due to overlapping bid ranges
void check_high_branching_invariant(int n, int l[], int r[]) {
    int branchingFactor = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if ((l[i] <= r[j] && r[i] >= l[j]) || (l[j] <= r[i] && r[j] >= l[i])) {
                branchingFactor++;
            }
        }
    }
    if (branchingFactor > 2) {  // High branching due to overlapping bid ranges
        cerr << "Warning: Performance bottleneck due to high recursion branching factor!" << endl;
        abort();
    }
}

void dzen(double tv, int x, int t) {
    if (x == n + 1 && t >= 2) {
        v += tv;
        return;
    }
    if (l[x] <= i && r[x] >= i) {
        dzen(tv / double(r[x] - l[x] + 1), x + 1, t + 1);
    }
    if (l[x] < i) {
        dzen(tv * (double(min(r[x] + 1, i) - l[x]) / (r[x] - l[x] + 1)), x + 1, t);
    }
    return;
}

void glen(double tv, int x, int t1, int t2) {
    if (x == n + 1 && t1 == 1 && t2 == 1) {
        v += tv;
        return;
    }
    if (l[x] <= i && r[x] >= i) {
        glen(tv / double(r[x] - l[x] + 1), x + 1, 1, t2);
    }
    if (l[x] < i) {
        glen(tv * (double(min(r[x] + 1, i) - l[x] + 1)), x + 1, t1, t2);
    }
    if (r[x] > i && t2 == 0) {
        glen(tv * (double(r[x] - max(l[x] - 1, i)) / (r[x] - l[x] + 1)), x + 1, t1, 1);
    }
    return;
}

int main() {
    cout << fixed << setprecision(10);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }

    // Perform invariant checks after reading inputs
    check_range_overlap_invariant(n, l, r);
    check_high_branching_invariant(n, l, r);

    for (i = 1; i <= 10000; i++) {
        v = 0;
        dzen(1, 1, 0);
        glen(1, 1, 0, 0);
        ans += v * i;
    }
    cout << ans;
    return 0;
}