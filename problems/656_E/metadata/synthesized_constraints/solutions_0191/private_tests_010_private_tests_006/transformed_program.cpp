#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
long long inf = 1e15;
int n;
long long a[12][12];
long long dp[12][12][12];

void check_edge_weight_variation(int maxWeight, int minWeight) {
    if (maxWeight > 10 * minWeight) {
        cerr << "Warning: Performance bottleneck condition triggered due to high edge weight variation!" << endl;
        abort();
    }
}

void check_vertex_count_invariant(int vertexCount) {
    if (vertexCount >= 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to maximum vertex count!" << endl;
        abort();
    }
}

void check_recursive_call_frequency(int callCount) {
    if (callCount > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered due to high recursion frequency!" << endl;
        abort();
    }
}

long long take(int i, int j, int k, int p) {
    static int callCount = 0;
    callCount++;
    check_recursive_call_frequency(callCount);
    return p == n ? inf
                  : min(dp[i][p][k - 1] + dp[p][j][k - 1], take(i, j, k, p + 1));
}

long long calc(int h, int k) {
    int i = h / n, j = h % n;
    return h == n * n ? 0 : ((dp[i][j][k] = take(i, j, k, 0)), calc(h + 1, k));
}

int floyd(int k) { return k == n + 1 ? 0 : (calc(0, k), floyd(k + 1)); }

int input(int h) {
    return h == n * n ? 0 : ((cin >> a[h / n][h % n]), input(h + 1));
}

int init(int h) {
    return h == n * n ? 0
                      : ((dp[h / n][h % n][0] = a[h / n][h % n]), init(h + 1));
}

long long maxim(int h) {
    int i = h / n, j = h % n;
    return h == n * n ? -1 : max(dp[i][j][n], maxim(h + 1));
}

int main() {
    cin >> n;
    check_vertex_count_invariant(n);
    input(0);

    int maxWeight = 0, minWeight = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                maxWeight = max(maxWeight, (int)a[i][j]);
                minWeight = min(minWeight, (int)a[i][j]);
            }
        }
    }
    check_edge_weight_variation(maxWeight, minWeight);

    init(0);
    floyd(1);
    cout << maxim(0);
    return 0;
}