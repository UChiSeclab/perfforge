#include <bits/stdc++.h>
using namespace std;
long long int MAX = 2e5 + 1;
long long int mod = 998244353LL;
const string no = "NO", yes = "YES";

void check_iteration_count(long long int coins, long long int diamonds) {
    if (coins > 10000 || diamonds > 10000) {
        cerr << "Warning: Performance bottleneck due to high number of iterations triggered!" << endl;
        abort();
    }
}

void check_sort_invariant(size_t size) {
    if (size > 50000) {
        cerr << "Warning: Performance bottleneck due to large sorting operation triggered!" << endl;
        abort();
    }
}

void check_resource_exhaustion(long long int coins, long long int diamonds, long long int n) {
    if ((coins == 100000 || diamonds == 100000) && n == 2) {
        cerr << "Warning: Resource exhaustion without successful pairing triggered!" << endl;
        abort();
    }
}

void solve() {
    long long int n, c[2];
    cin >> n >> c[0] >> c[1];
    
    // Check for resource exhaustion invariant
    check_resource_exhaustion(c[0], c[1], n);
    
    vector<vector<long long int> > dp[2], v[2];
    for (long long int i = 0; i < n; i++) {
        long long int b, p;
        char x;
        cin >> b >> p >> x;
        v[x - 'C'].push_back({p, b});
    }

    // Check for sorting invariant before sorting the vectors
    check_sort_invariant(v[0].size());
    check_sort_invariant(v[1].size());

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());

    // Check for iteration count invariant before entering the loop
    check_iteration_count(c[0], c[1]);
    
    for (long long int i = 0; i < 2; i++) {
        dp[i].assign(c[i] + 1, vector<long long int>(2, -1e9));
        long long int ptr = 0;
        for (long long int j = 1; j < c[i] + 1; j++) {
            dp[i][j][0] = dp[i][j - 1][0];
            dp[i][j][1] = dp[i][j - 1][1];
            while (ptr < v[i].size() && v[i][ptr][0] == j) {
                long long int l = c[i] - j;
                l = min(l, j);
                if (dp[i][l][0] != -1e9) {
                    dp[i][j][1] = max(dp[i][j][1], v[i][ptr][1] + dp[i][l][0]);
                }
                dp[i][j][0] = max(dp[i][j][0], v[i][ptr][1]);
                ptr++;
            }
        }
    }
    
    long long int ans = 0;
    for (long long int i = 0; i < 2; i++) {
        ans = max(ans, dp[i][c[i]][1]);
    }
    ans = max(ans, dp[0][c[0]][0] + dp[1][c[1]][0]);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t = 1;
    for (long long int i = 0; i < t; i++) {
        solve();
    }
}