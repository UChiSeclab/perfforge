#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 1e7 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int INF = 2e9;
const int seed = 131;
int n, c, a[N], sum[N], pre[N];
vector<int> G[N];

// Check for high maximum value relative to c
void check_max_value_invariant(int mx, int c) {
    if (mx > 10 * c) {  // Arbitrary threshold ratio chosen
        cerr << "Warning: Performance bottleneck condition triggered due to high maximum value relative to c!" << endl;
        abort();
    }
}

// Check for sparse target value
void check_sparse_target_invariant(int n, int countC) {
    if (countC < n / 10) {  // Arbitrary threshold: if less than 10% of elements are `c`
        cerr << "Warning: Performance bottleneck condition triggered due to sparse target value c!" << endl;
        abort();
    }
}

// Check for dense population of G
void check_dense_population_invariant(const vector<int> G[], int n, int mx) {
    for (int i = 1; i <= mx; ++i) {
        if (G[i].size() > n / 5) {  // Arbitrary threshold: if vector size exceeds 20% of n
            cerr << "Warning: Performance bottleneck condition triggered due to dense population of G!" << endl;
            abort();
        }
    }
}

int main() {
    int mx = 0;
    scanf("%d%d", &n, &c);
    int countC = 0;  // Count occurrences of c in the array
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + (a[i] == c);
        if (a[i] == c) countC++;
        mx = max(mx, a[i]);
    }

    // Insert check for high maximum value in array
    check_max_value_invariant(mx, c);

    for (int i = 1; i <= n; ++i) {
        G[a[i]].push_back(-(sum[i - 1] - sum[pre[a[i]]]));
        G[a[i]].push_back(1);
        pre[a[i]] = i;
    }

    // Insert check for sparse target value
    check_sparse_target_invariant(n, countC);

    int ans = 0;
    for (int i = 1; i <= mx; ++i) {
        if (i == c) continue;
        int res = 0, sum = 0;
        for (auto &x : G[i]) {
            sum = max(0, sum + x);
            res = max(res, sum);
        }
        ans = max(ans, res);
    }

    // Insert check for dense population of G
    check_dense_population_invariant(G, n, mx);

    printf("%d\n", ans + sum[n]);
    return 0;
}