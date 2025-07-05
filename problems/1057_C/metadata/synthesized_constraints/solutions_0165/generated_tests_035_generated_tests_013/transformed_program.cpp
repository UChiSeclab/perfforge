#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long dp[51][2051];
long long a[100];

void check_sequence_invariant(const long long* a, const string& color, long long n) {
    long long maxSequenceLength = 0;
    long long currentSequenceLength = 1;

    for (long long i = 1; i < n; ++i) {
        if (a[i] < a[i + 1] && color[i - 1] != color[i]) {
            ++currentSequenceLength;
        } else {
            maxSequenceLength = max(maxSequenceLength, currentSequenceLength);
            currentSequenceLength = 1;
        }
    }
    maxSequenceLength = max(maxSequenceLength, currentSequenceLength);

    if (maxSequenceLength > 10) { // Arbitrary threshold for detecting potentially long sequences
        cerr << "Warning: Performance bottleneck - long sequence of increasing candies and alternating colors." << endl;
        abort();
    }
}

void check_density_invariant(const long long* a, const string& color, long long n, long long s) {
    long long validCandidateCount = 0;

    for (long long i = max(1LL, s - 5); i <= min(n, s + 5); ++i) { // Check a small range around the start
        if (a[i] > a[s] && color[i - 1] != color[s - 1]) {
            ++validCandidateCount;
        }
    }

    if (validCandidateCount > 5) { // Arbitrary threshold for dense regions
        cerr << "Warning: Performance bottleneck - dense region of valid candidate boxes." << endl;
        abort();
    }
}

void check_candy_value_invariant(const long long* a, long long n) {
    long long similarCountRange = 0;
    for (long long i = 1; i < n; ++i) {
        if (a[i] == a[i + 1]) {
            ++similarCountRange;
        }
    }

    if (similarCountRange > 10) { // Arbitrary threshold for similar candy counts
        cerr << "Warning: Performance bottleneck - many boxes have similar candy counts." << endl;
        abort();
    }
}

void go() {
    long long n, s, k;
    cin >> n >> s >> k;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    string color;
    cin >> color;

    // Checking invariants after reading input
    check_sequence_invariant(a, color, n);
    check_density_invariant(a, color, n, s);
    check_candy_value_invariant(a, n);

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
    for (long long i = 1; i <= n; i++) {
        q.push({abs(i - s), i});
        dp[i][abs(i - s)] = a[i];
    }
    while (!q.empty()) {
        long long sec = q.top().first;
        long long pos = q.top().second;
        q.pop();
        if (dp[pos][sec] >= k) {
            cout << sec;
            return;
        }
        for (long long i = 1; i <= n; i++) {
            if (a[i] > a[pos] && color[pos - 1] != color[i - 1] && dp[i][sec + abs(i - pos)] < dp[pos][sec] + a[i]) {
                q.push({sec + abs(i - pos), i});
                dp[i][sec + abs(i - pos)] = dp[pos][sec] + a[i];
            }
        }
    }
    cout << -1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    long long t = 1;
    cout << fixed << setprecision(12);
    while (t--) {
        go();
    }
}