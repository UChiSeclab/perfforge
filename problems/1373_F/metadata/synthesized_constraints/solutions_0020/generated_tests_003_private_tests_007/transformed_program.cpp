#include <bits/stdc++.h>
using namespace std;

long long n, t[5000005], save[5000005], a[1000005], b[1000005], pown, l, r, ad;

// Checker functions based on performance invariants
void check_segment_tree_invariant(int pown, int callCount) {
    if (pown > 100000 && callCount > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive segment tree updates!" << endl;
        abort();
    }
}

void check_backtracking_invariant(int n, long long asum, long long bsum) {
    if (n > 100 && (bsum - asum) < n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive backtracking in station assignment!" << endl;
        abort();
    }
}

void check_large_input_invariant(int n) {
    if (n > 500000) {
        cerr << "Warning: Performance bottleneck condition triggered - handling large input size!" << endl;
        abort();
    }
}

void solv(long long x) {
    for (int i = x - 1; i >= 1; i--) {
        a[i] -= b[i];
        a[i] = max(a[i], 0LL);
        long long ind = i - 1;
        if (!ind && x != 1) ind = n;
        if (a[i] > 0 && b[ind] < a[i]) {
            printf("NO\n");
            return;
        }
        b[ind] -= a[i];
    }
    for (int i = n; i >= x; i--) {
        a[i] -= b[i];
        a[i] = max(a[i], 0LL);
        long long ind = i - 1;
        if (i == x) ind = 0;
        if (a[i] > 0 && a[i] > b[ind]) {
            printf("NO\n");
            return;
        }
        b[ind] -= a[i];
    }
    printf("YES\n");
}

void add(long long x, long long L, long long R, int& callCount) {
    callCount++;
    if (L > r || R < l) return;
    if (L >= l && R <= r) {
        t[x] += ad;
        save[x] += ad;
        return;
    }
    if (save[x]) {
        t[2 * x] += save[x];
        t[2 * x + 1] += save[x];
        save[2 * x] += save[x];
        save[2 * x + 1] += save[x];
        save[x] = 0;
    }
    add(2 * x, L, (L + R) / 2, callCount);
    add(2 * x + 1, (L + R) / 2 + 1, R, callCount);
    t[x] = t[2 * x];
    if (t[2 * x + 1] < t[x]) t[x] = t[2 * x + 1];
}

void solve() {
    scanf("%I64d", &n);

    // Check for large input invariant
    check_large_input_invariant(n);

    pown = 1;
    while (pown <= n) pown *= 2;
    for (int i = 1; i <= 2 * pown; i++) {
        t[i] = 0;
        save[i] = 0;
    }
    long long asum = 0, bsum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        asum += a[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &b[i]);
        bsum += b[i];
    }

    // Check for excessive backtracking invariant
    check_backtracking_invariant(n, asum, bsum);

    int callCount = 0;  // Track the number of `add` function calls

    for (int i = 1; i <= n; i++) {
        l = i, r = n, ad = b[i] - a[i];
        add(1, 1, pown, callCount);

        // Check for segment tree invariant after each full `add` operation
        check_segment_tree_invariant(pown, callCount);
    }
    if (t[1] >= 0) {
        solv(1);
        return;
    }
    for (int i = 1; i < n; i++) {
        l = 1, r = pown, ad = -(b[i] - a[i]);
        add(1, 1, pown, callCount);

        // Check for segment tree invariant
        check_segment_tree_invariant(pown, callCount);

        l = i, r = i, ad = -asum + a[i] + bsum - b[i] + (b[i] - a[i]);
        add(1, 1, pown, callCount);

        // Check for segment tree invariant
        check_segment_tree_invariant(pown, callCount);

        if (t[1] >= 0) {
            solv(i + 1);
            return;
        }
    }
    printf("NO\n");
}

int main() {
    long long q;
    cin >> q;
    while (q--) solve();
    return 0;
}