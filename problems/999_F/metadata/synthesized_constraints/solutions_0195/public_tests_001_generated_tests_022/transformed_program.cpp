#include <bits/stdc++.h>
using namespace std;

void guan() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int maxn = 100010;
const long long mod = 1e9 + 7;
const double pi = acos(-1.0);
const long long maxx = 1LL << 61;
const double eps = 1e-7;
int n, k;
inline int read() { return cin >> n >> k ? 1 : 0; }
int dp[510][12][5100];
int h[555], f[555];
map<int, int> cnt;
map<int, int> p;

void init() {
    int tk = k;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= 10; i++) dp[0][i][0] = 0;
    for (int i = 1; i <= 505; i++) {
        for (int k = 1; k <= 5010; ++k) {
            for (int j = 1; j <= tk; j++) {
                int maxx = 0;
                if (j > k) break;
                for (int q = 1; q <= j; q++) {
                    maxx = max(dp[i - 1][q][k - j], maxx);
                }
                dp[i][j][k] = h[j] + maxx;
            }
        }
    }
}

void check_player_card_invariant(int n, int k) {
    if (n > 400 && k > 8) { // Example thresholds based on problem constraints
        cerr << "Warning: Too many players with too many cards each - potential performance bottleneck!" << endl;
        abort();
    }
}

void check_card_diversity_invariant(const map<int, int>& cnt, int n) {
    if (cnt.size() > n * 3) { // Assuming high diversity if unique card numbers exceed three times the number of players
        cerr << "Warning: High card diversity relative to number of players - potential performance bottleneck!" << endl;
        abort();
    }
}

void check_favorite_diversity_invariant(const map<int, int>& p) {
    if (p.size() > 300) { // Example threshold for favorite number diversity
        cerr << "Warning: High diversity of favorite numbers - potential performance bottleneck!" << endl;
        abort();
    }
}

void solve() {
    for (int i = 1; i <= k * n; i++) {
        int t;
        cin >> t;
        cnt[t]++;
    }

    check_card_diversity_invariant(cnt, n); // Check card diversity after reading inputs

    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        p[f[i]]++;
    }
    
    check_favorite_diversity_invariant(p); // Check favorite number diversity

    for (int i = 1; i <= k; i++) cin >> h[i];

    init();

    int ans = 0;
    for (map<int, int>::iterator it = p.begin(); it != p.end(); ++it) {
        int nump = it->second, sum = cnt[it->first];
        sum = min(sum, nump * k);
        int maxx = 0;
        for (int i = 1; i <= k; i++) {
            maxx = max(maxx, dp[nump][i][sum]);
        }
        ans += maxx;
    }
    cout << ans << endl;
}

int main() {
    guan();
    int t = 1;
    while (t--) {
        while (read()) {
            check_player_card_invariant(n, k); // Check player-card invariant after reading n and k
            solve();
        }
    }
    return 0;
}