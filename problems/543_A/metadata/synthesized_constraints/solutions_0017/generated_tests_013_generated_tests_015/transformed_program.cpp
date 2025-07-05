#include <bits/stdc++.h>
using namespace std;

int n, m, b, mod;
int flip = 0;
vector<vector<vector<int>>> DP;
vector<int> V;

// Checker functions for performance bottlenecks
void check_large_b(int n, int m, int b) {
    if ((b > m / 2 && n < m / 2) || (b > m / 2 && b > 250)) {
        cerr << "Warning: Performance bottleneck condition triggered - large b relative to team size or lines" << endl;
        abort();
    }
}

void check_bug_distribution(const vector<int>& V, int b) {
    int high_bug_programmers = 0;
    for (int bugs : V) {
        if (bugs > b / 4) {
            high_bug_programmers++;
        }
    }
    if (high_bug_programmers > V.size() / 3) {
        cerr << "Warning: Performance bottleneck condition triggered - high bug rates per line" << endl;
        abort();
    }
}

void check_m_b_combination(int m, int b) {
    if (m > 400 && b > 400) {
        cerr << "Warning: Performance bottleneck condition triggered - large m and b causing many state transitions" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> b >> mod;
    V = vector<int>(n);
    for (int i = 0; i < n; ++i) cin >> V[i];

    // Insert performance checkers after input reading
    check_large_b(n, m, b);
    check_bug_distribution(V, b);
    check_m_b_combination(m, b);

    DP = vector<vector<vector<int>>>(
        2, vector<vector<int>>(m + 1, vector<int>(b + 1, 0)));
    DP[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        flip = !flip;
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= b; ++k) {
                DP[flip][j][k] = DP[!flip][j][k];
                if (j > 0 && k >= V[i]) DP[flip][j][k] += DP[flip][j - 1][k - V[i]];
                DP[flip][j][k] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= b; ++i) {
        ans = (ans + DP[flip][m][i]) % mod;
    }
    cout << ans << "\n";
    return 0;
}