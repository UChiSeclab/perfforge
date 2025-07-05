#include <bits/stdc++.h>
using namespace std;
int const inf = 1000 * 1000 * 1000;
long long const inf64 = 1ll * inf * inf;
int const N = 1e5 + 5;
int const M = 3e5 + 5;
int n, m;
int w[N];
int c[N];
vector<int> perm;
int mn[N];
int mn2[N];
int mx[N];
long long pc[N];
long long pw[N];
int sz;
long long value[M];

void check_iteration_overhead(int m) {
    if (m > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration overhead due to large m!" << endl;
        abort();
    }
}

void check_large_prefix_sum_search(int n, int* pw) {
    if (n > 50000) {
        cerr << "Warning: Performance bottleneck condition triggered - large prefix sum array causing repeated binary searches!" << endl;
        abort();
    }
}

void check_inefficient_nested_calculations(int sz) {
    if (sz > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient nested calculations due to large sz!" << endl;
        abort();
    }
}

int main() {
    scanf("%d %d", &n, &m);

    // Check for high iteration overhead based on the value of m
    check_iteration_overhead(m);

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &w[i], &c[i]);
        if (w[i] <= 2) {
            perm.push_back(i);
        }
    }
    sort((perm).begin(), (perm).end(),
         [&](int i, int j) { return 2 * c[i] / w[i] > 2 * c[j] / w[j]; });
    sz = (int)perm.size();

    // Check for inefficient nested calculations based on the value of sz
    check_inefficient_nested_calculations(sz);

    for (int i = sz - 1; i >= 0; i--) {
        if (i == sz - 1) {
            mx[i] = -inf;
        } else
            mx[i] = mx[i + 1];
        if (w[perm[i]] == 1) mx[i] = max(mx[i], c[perm[i]]);
    }
    for (int i = 0; i < sz; i++) {
        pc[i] = (i > 0 ? pc[i - 1] : 0ll) + c[perm[i]];
        pw[i] = (i > 0 ? pw[i - 1] : 0ll) + w[perm[i]];
        if (i == 0)
            mn[i] = mn2[i] = inf;
        else
            mn[i] = mn[i - 1], mn2[i] = mn2[i - 1];
        if (w[perm[i]] == 1) {
            mn[i] = min(mn[i], c[perm[i]]);
        } else {
            mn2[i] = min(mn2[i], c[perm[i]]);
        }
    }

    // Check for large prefix sum searches affecting performance
    check_large_prefix_sum_search(n, pw);

    for (int j = 0; j < M; j++) {
        int idx = lower_bound(pw, pw + sz, j) - pw;
        int ql = max(0, idx - 3);
        int qr = min(sz - 1, idx + 3);
        for (int i = ql; i <= qr; i++) {
            if (pw[i] <= j) {
                value[j] = max(value[j], pc[i]);
            } else if (pw[i] == j + 1) {
                value[j] = max(value[j], pc[i] - mn[i]);
                value[j] = max(value[j], pc[i] - mn2[i] + (i + 1 < sz ? mx[i] : -inf));
            }
        }
    }
    long long res = 0;
    for (int j = 0; j <= m; j++) {
        res = max(res, value[j]);
        if (j > 0) {
            value[j] = max(value[j], value[j - 1]);
        }
    }
    vector<long long> arr;
    for (int i = 1; i <= n; i++) {
        if (w[i] == 3) {
            arr.push_back(c[i]);
        }
    }
    sort((arr).begin(), (arr).end());
    reverse((arr).begin(), (arr).end());
    for (int i = 0; i < (int)arr.size(); i++) {
        if (i > 0) arr[i] += arr[i - 1];
        if (3 * (i + 1) > m) break;
        res = max(res, value[m - 3 * (i + 1)] + arr[i]);
    }
    cout << res << "\n";
    return 0;
}