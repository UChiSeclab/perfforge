#include <bits/stdc++.h>
using namespace std;

template <class T>
void minn(T &a, T b) {
    a = min(a, b);
}

template <class T>
void maxx(T &a, T b) {
    a = max(a, b);
}

void io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const long long MOD = 1000000007LL;
const long long PRIME = 105943LL;
const long long INF = 1e18;
int n;
string s;
long long a[101];
long long ans[100][100];
long long dp[100][100][2][101];

long long fans(int l, int r);
long long fdp(int l, int r, int t, int c);

void check_recursive_calls(int max_consecutive, int max_score) {
    if (max_consecutive > 25 && max_score > 1000000000) {
        cerr << "Warning: Performance bottleneck condition triggered due to high branching factor and deep recursion!" << endl;
        abort();
    }
}

void check_score_invariant(long long* a, int n) {
    bool excessive_score = false;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 1000000000) {
            excessive_score = true;
            break;
        }
    }
    if (excessive_score) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive score contribution for longer substrings!" << endl;
        abort();
    }
}

void check_consecutive_sequences(const string& s) {
    int max_consecutive = 0;
    int current_consecutive = 1;
    for (size_t i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            current_consecutive++;
        } else {
            max_consecutive = max(max_consecutive, current_consecutive);
            current_consecutive = 1;
        }
    }
    max_consecutive = max(max_consecutive, current_consecutive);
    
    if (max_consecutive > 25) {
        cerr << "Warning: Performance bottleneck condition triggered due to deep recursive exploration!" << endl;
        abort();
    }
}

long long fans(int l, int r) {
    if (l > r) return 0;
    long long &best = ans[l][r];
    if (best != 0x3F3F3F3F3F3F3F3F) return best;
    best = -INF;
    for (int c = 1; c <= (int)r - l + 1; c++)
        for (int t = 0; t < (int)(2); t++) maxx(best, fdp(l, r, t, c) + a[c]);
    return best;
}

long long fdp(int l, int r, int t, int c) {
    if (c == 0) return fans(l, r);
    if (l > r) return -INF;
    int psz = 0;
    for (int i = l; i <= (int)r; i++)
        if (s[i] == t + '0') psz++;
    if (c > psz) return -INF;
    long long &best = dp[l][r][t][c];
    if (best != 0x3F3F3F3F3F3F3F3F) return best;
    best = -INF;
    for (int m = l; m <= (int)r; m++)
        if (s[m] == t + '0') maxx(best, fans(l, m - 1) + fdp(m + 1, r, t, c - 1));
    return best;
}

int main() {
    io();
    cin >> n >> s;
    for (int i = 1; i <= (int)n; i++) cin >> a[i];

    // Insert performance checks
    check_score_invariant(a, n); // Check for excessive score contributions
    check_consecutive_sequences(s); // Check for long consecutive sequences

    memset(ans, 0x3F3F3F3F3F3F3F3F, sizeof ans);
    memset(dp, 0x3F3F3F3F3F3F3F3F, sizeof dp);

    cout << fans(0, n - 1) << "\n";
}