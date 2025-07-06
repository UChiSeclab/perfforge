#include <bits/stdc++.h>
using namespace std;

void check_large_k_invariant(int K) {
    if (K >= 60) {
        cerr << "Warning: Performance bottleneck condition triggered - large K value!" << endl;
        abort();
    }
}

void check_high_iteration_invariant(int K, int P) {
    if (K > 50 && P > 35) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count in nested loops!" << endl;
        abort();
    }
}

void check_dp_array_invariant(int K) {
    if (K > 60) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient DP array operations!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;

    // Insert checker for large K invariant
    check_large_k_invariant(K);

    vector<vector<int>> a(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) cin >> a[i][j];

    vector<int> dp(K, -1e9);
    dp[0] = 0;
    int P = M / 2;

    // Insert checker for high iteration count and inefficient DP array operations
    check_high_iteration_invariant(K, P);
    check_dp_array_invariant(K);

    for (int i = 0; i < N; ++i) {
        vector<vector<int>> knap(P + 1, vector<int>(K, -1e9));
        knap[0][0] = 0;
        for (int j = 0; j < M; ++j)
            for (int take = P - 1; take >= 0; --take)
                for (int rest = 0; rest < K; ++rest)
                    knap[take + 1][(a[i][j] + rest) % K] = max(
                        knap[take + 1][(a[i][j] + rest) % K], knap[take][rest] + a[i][j]);
        
        vector<int> ndp(K, -1e9);
        for (int rest1 = 0; rest1 < K; ++rest1)
            for (int rest2 = 0; rest2 < K; ++rest2)
                for (int take = 0; take <= P; ++take)
                    ndp[(rest1 + rest2) % K] = max(ndp[(rest1 + rest2) % K],
                                                    dp[rest1] + knap[take][rest2]);
        
        swap(dp, ndp);
    }

    cout << dp[0] << "\n";
    return 0;
}