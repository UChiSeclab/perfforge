#include <bits/stdc++.h>
using namespace std;
const int N = 204;
char s[N];
char t[100];
int f[N][N][N];
const int INF = 1 << 30;

void check_max_replacements_invariant(int n, int k, const string &s, const string &t) {
    int count_t1 = count(s.begin(), s.end(), t[0]);
    int count_t2 = count(s.begin(), s.end(), t[1]);
    if ((k >= n - 1) && (count_t1 + count_t2 >= n - 1)) {
        cerr << "Warning: Performance bottleneck condition triggered due to maximal replacements with high overlap!" << endl;
        abort();
    }
}

void check_subsequence_potential_invariant(int n, int k, const string &s, const string &t) {
    int count_t1 = count(s.begin(), s.end(), t[0]);
    int count_t2 = count(s.begin(), s.end(), t[1]);
    if ((k >= n / 2) && (count_t1 > n / 2 || count_t2 > n / 2)) {
        cerr << "Warning: Performance bottleneck condition triggered due to high subsequence formation potential!" << endl;
        abort();
    }
}

void check_dp_table_size_invariant(int n, int k) {
    if (n >= 200 && k >= 100) {
        cerr << "Warning: Performance bottleneck condition triggered due to large dynamic programming table size!" << endl;
        abort();
    }
}

auto solve() -> void {
    int n, k;
    cin >> n >> k;
    cin >> s;
    cin >> (t + 1);

    // Convert to string for checkers
    string str_s(s, s + n);
    string str_t(t + 1, t + 3);

    // Perform checks based on invariants
    check_max_replacements_invariant(n, k, str_s, str_t);
    check_subsequence_potential_invariant(n, k, str_s, str_t);
    check_dp_table_size_invariant(n, k);

    for (int i = n; i >= 0; --i) {
        for (int j = 0; j <= k; ++j) {
            for (int t2 = 0; t2 <= n; ++t2) f[i][j][t2] = -INF;
        }
    }
    f[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int cnt = 0; cnt <= n; ++cnt) {
                f[i + 1][j][cnt + (t[1] == s[i])] =
                    max(f[i + 1][j][cnt + (t[1] == s[i])],
                        f[i][j][cnt] + (s[i] == t[2] ? cnt : 0));
                if (j < k) {
                    f[i + 1][j + 1][cnt + 1] =
                        max(f[i + 1][j + 1][cnt + 1],
                            f[i][j][cnt] + (t[1] == t[2] ? cnt : 0));
                    f[i + 1][j + 1][cnt + (t[1] == t[2])] =
                        max(f[i + 1][j + 1][cnt + (t[1] == t[2])], f[i][j][cnt] + cnt);
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= k; ++j) {
        for (int t2 = 0; t2 <= n; ++t2) {
            ans = max(ans, f[n][j][t2]);
        }
    }
    cout << ans << '\n';
}

auto main() -> int {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}