#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long mod = 1e9 + 7;
const long long N = 80 + 5, K = 105;
const int si = (1 << 20);
const long long add = 1e4;
const long long M = 1e5 + 5;
const double INFdb = 1e10;
bool color[M];
int n, m;
pair<int, int> a[N];
int dp[M];

void check_coverage_gaps_invariant(int n, const pair<int, int> a[], int m) {
    for (int i = 1; i < n; ++i) {
        if (a[i + 1].first - (a[i].first + a[i].second) > m / n) {
            cerr << "Warning: Performance bottleneck condition triggered - large coverage gaps detected!" << endl;
            abort();
        }
    }
}

void check_position_density_invariant(int m, const bool color[]) {
    int uncovered_count = 0;
    for (int i = 1; i <= m; ++i) {
        if (!color[i]) {
            uncovered_count++;
            if (uncovered_count > m / 10) {  // Arbitrary threshold for high density
                cerr << "Warning: Performance bottleneck condition triggered - high density of uncovered positions!" << endl;
                abort();
            }
        }
    }
}

void check_dp_backtracking_invariant(int m, const int dp[]) {
    int backtrack_count = 0;
    for (int i = 1; i <= m; ++i) {
        if (dp[i] > dp[i - 1] + 1) {
            backtrack_count++;
            if (backtrack_count > m / 50) {  // Arbitrary threshold for excessive backtracking
                cerr << "Warning: Performance bottleneck condition triggered - excessive DP backtracking!" << endl;
                abort();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
        for (int j = max(1, a[i].first - a[i].second);
             j <= min(m, a[i].first + a[i].second); ++j)
            color[j] = 1;
    }

    // Check invariants after reading input and initial marking
    check_coverage_gaps_invariant(n, a, m);
    check_position_density_invariant(m, color);

    sort(a + 1, a + 1 + n);
    for (int i = 0; i < M; ++i) dp[i] = M;
    dp[0] = 0;
    for (int i = 1; i <= m; ++i) {
        if (color[i])
            dp[i] = min(dp[i], dp[i - 1]);
        else
            dp[i] = min(dp[i], dp[i - 1] + 1);
        for (int j = 1; j <= n; ++j) {
            if (a[j].first > i) break;
            int dist = (i - a[j].first) - a[j].second;
            if (dist < 0) dist = 0;
            int pos = max(0, a[j].first - a[j].second - dist - 1);
            dp[i] = min(dp[i], dp[pos] + dist);
        }
    }

    // Check the third invariant after dynamic programming
    check_dp_backtracking_invariant(m, dp);

    cout << dp[m];
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}