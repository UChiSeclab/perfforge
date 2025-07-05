#include <bits/stdc++.h>
using namespace std;
const int N = (2 << 18);
const long long INF = 2e18;
long long seg[N << 2];

void check_segment_tree_operations(int n, long long operationCount) {
    if (operationCount > n * log2(n)) {
        cerr << "Warning: Performance bottleneck in segment tree operations!" << endl;
        abort();
    }
}

void check_recursive_traversal(int recursionDepth, int n) {
    if (recursionDepth > log2(n) + 10) {
        cerr << "Warning: Recursion depth exceeding expected limits!" << endl;
        abort();
    }
}

void check_nested_loops(int loopIterations, int n) {
    if (loopIterations > n * log2(n)) {
        cerr << "Warning: Excessive iterations in nested loops!" << endl;
        abort();
    }
}

void check_input_size(int n) {
    if (n >= (1 << 18)) {
        cerr << "Warning: Input size at maximum constraint, potential slowdown!" << endl;
        abort();
    }
}

void build(int rt, int l, int r, int depth) {
    check_recursive_traversal(depth, N);
    seg[rt] = INF;
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid, depth + 1);
    build(rt << 1 | 1, mid + 1, r, depth + 1);
}

void update(int rt, int l, int r, int x, long long w, long long& updateCount) {
    updateCount++;
    if (l == r) {
        seg[rt] = w;
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        update(rt << 1, l, mid, x, w, updateCount);
    else
        update(rt << 1 | 1, mid + 1, r, x, w, updateCount);
    seg[rt] = min(seg[rt << 1 | 1], seg[rt << 1]);
}

long long query(int rt, int l, int r, int x, int y, long long& queryCount) {
    queryCount++;
    if (x <= l && y >= r) {
        return seg[rt];
    }
    int mid = l + r >> 1;
    long long res = INF;
    if (x <= mid) res = min(res, query(rt << 1, l, mid, x, y, queryCount));
    if (y > mid) res = min(res, query(rt << 1 | 1, mid + 1, r, x, y, queryCount));
    return res;
}

long long a[N], dp[N];

int main() {
    int n;
    scanf("%d", &n);
    
    // Check input size for potential slowdown
    check_input_size(n);
    
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    int cnt = 0, m = n;
    while (m) {
        m >>= 1;
        cnt++;
    }

    build(1, 1, n, 0); // Initialize the segment tree, track recursion depth

    long long updateCount = 0, queryCount = 0;
    
    dp[n] = a[n];
    if (a[n] == -1) {
        printf("0\n");
        return 0;
    }
    
    update(1, 1, n, n, dp[n], updateCount);
    long long ans = -1;
    cnt--;
    m = 1;

    int loopIterations = 0;

    for (int i = 1; i <= cnt; i++) {
        if (ans != -1) break;
        for (int j = (1 << (cnt - i)); j <= n; j++) {
            loopIterations++;
            if (j > n - i) {
                dp[j] = INF;
                update(1, 1, n, j, dp[j], updateCount);
                continue;
            }
            long long res = query(1, 1, n, j + 1, n, queryCount);
            dp[j] = res + a[j];
            if (a[j] == -1) {
                ans = res;
                break;
            }
            update(1, 1, n, j, dp[j], updateCount);
        }
        m++;
    }

    // Check for excessive nested loop iterations
    check_nested_loops(loopIterations, n);

    // Check the segment tree operation counts
    check_segment_tree_operations(n, updateCount + queryCount);

    printf("%lld\n", ans);
    return 0;
}