#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int maxm = 305;
int c[maxm];
int a[maxn], b[maxn * maxn * 2];
int dp[maxm];
int suf[maxn * maxn], pre[maxn * maxn];

void check_t_invariance(int t, int n) {
    if (t > 2 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - T is significantly larger than 2n!" << endl;
        abort();
    }
}

void check_nested_loop_complexity(int n, int t) {
    int b_size = n * n; // Size of b in the worst case path
    if (b_size > 10000) { // Arbitrary threshold considering constraints
        cerr << "Warning: Performance bottleneck condition triggered - potential complexity due to large constructed array!" << endl;
        abort();
    }
}

void check_inner_loop_cost(int max_elem) {
    if (max_elem >= 300) {
        cerr << "Warning: Performance bottleneck condition triggered - costly operations over wide range in loop!" << endl;
        abort();
    }
}

void check_sequential_processing(int t, int n) {
    if (t > 5 * n) { // Arbitrary threshold to detect excessive processing
        cerr << "Warning: Performance bottleneck condition triggered - excessive sequential processing for large T!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, t;
    int mx;
    int ans = 0;
    scanf("%d %d", &n, &t);

    // Insert check for invariants
    check_t_invariance(t, n);
    check_nested_loop_complexity(n, t);
    check_sequential_processing(t, n);

    for (int i = 1; i < n + 1; ++i) {
        scanf("%d", &a[i]);
        ++c[a[i]];
    }

    int max_element = *max_element(a + 1, a + n + 1);
    check_inner_loop_cost(max_element);

    if (t <= n * 2) {
        for (int i = 1; i < n + 1; ++i) {
            int k = i;
            for (int j = 1; j < t + 1; ++j) {
                b[k] = a[i];
                k += n;
            }
        }
        int n_ = n * t;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < n_ + 1; ++i) {
            mx = 0;
            for (int j = 1; j < b[i] + 1; ++j) mx = max(mx, dp[j]);
            pre[i] = ++mx;
            dp[b[i]] = mx;
        }
        for (int i = 1; i < n_ + 1; ++i) ans = max(ans, pre[i]);
        printf("%d\n", ans);
        return 0;
    }

    for (int i = 1; i < n + 1; ++i) {
        int k = i;
        for (int j = 1; j < n + 1; ++j) {
            b[k] = a[i];
            k += n;
        }
    }
    int n_ = n * n;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n_ + 1; ++i) {
        mx = 0;
        for (int j = 1; j < b[i] + 1; ++j) mx = max(mx, dp[j]);
        pre[i] = ++mx;
        dp[b[i]] = mx;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = n_ + 1 - 1; i >= 1; --i) {
        mx = 0;
        for (int j = b[i]; j < maxm; ++j) mx = max(mx, dp[j]);
        suf[i] = ++mx;
        dp[b[i]] = mx;
    }
    int tmp, n2 = n + n;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (a[j] < a[i]) continue;
            tmp = pre[i + n_ - n] + suf[j] + c[a[i]] * (t - n2);
            ans = max(ans, tmp);
        }
    }
    printf("%d\n", ans);
    return 0;
}