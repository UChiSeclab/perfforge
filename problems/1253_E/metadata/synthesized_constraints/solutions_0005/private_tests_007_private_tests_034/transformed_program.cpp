#include <bits/stdc++.h>
using namespace std;

const long long INFL = 1LL << 60;
const long long INF = INFL;
long long MOD = 1000000007;
vector<long long> dy = {0, -1, 0, 1, 1, 1, -1, -1, 0};
vector<long long> dx = {1, 0, -1, 0, 1, -1, 1, -1, 0};

const int MAXcomb = 200010;
long long fac[MAXcomb], finv[MAXcomb], inv[MAXcomb];
const long long N_ = (1 << 18);
long long seg[2 * N_ - 1];

// Check if the initial scopes leave large gaps unaddressed, causing many updates
void check_large_update_requirement(const vector<pair<long long, long long>>& antennas, long long m) {
    int uncovered_length = m;
    for (const auto& antenna : antennas) {
        uncovered_length -= (2 * antenna.second + 1); // Reduce uncovered length by each antenna's current coverage
    }
    if (uncovered_length > 50000) {  // Arbitrary threshold based on problem size
        cerr << "Warning: Performance bottleneck condition triggered - large update requirement due to initial antenna scopes!" << endl;
        abort();
    }
}

// Check for potential excessive operations due to sparse initial coverage
void check_sparse_initial_coverage(const vector<pair<long long, long long>>& antennas, long long m) {
    int lastEndCovered = 0;
    bool isSparse = false;
    for (const auto& antenna : antennas) {
        if (antenna.first - antenna.second > lastEndCovered + 1000) { // Checks gaps in coverage
            isSparse = true;
            break;
        }
        lastEndCovered = antenna.first + antenna.second;
    }
    
    if (isSparse) {
        cerr << "Warning: Performance bottleneck condition triggered - sparse initial coverage leading to excessive updates!" << endl;
        abort();
    }
}

// Check if high m might lead to excessive loop iterations
void check_high_m_value(long long m) {
    if (m > 80000) { // Arbitrary threshold for 'large' m
        cerr << "Warning: Performance bottleneck condition triggered - high value of m leading to excessive iterations!" << endl;
        abort();
    }
}

void init_seg() {
    for (long long i = 0; i < (2 * N_ - 1); i++) {
        seg[i] = INFL;
    }
}

void update(long long k, long long x) {
    k += N_ - 1;
    seg[k] = min(x, seg[k]);
    while (k > 0) {
        k = (k - 1) / 2;
        seg[k] = min(seg[k], min(seg[2 * k + 1], seg[2 * k + 2]));
    }
}

long long getminimum(long long x, long long y, long long k = 0, long long left = 0, long long right = N_) {
    if (right <= x || y <= left) return INFL;
    if (x <= left && right <= y) return seg[k];
    long long mid = (left + right) / 2;
    long long l = getminimum(x, y, 2 * k + 1, left, mid);
    long long r = getminimum(x, y, 2 * k + 2, mid, right);
    return min(l, r);
}

void solve() {
    long long N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> l(N);
    for (long long i = 0; i < (N); i++) {
        cin >> l[i].first >> l[i].second;
    }

    // Inserted checker functions before processing
    check_large_update_requirement(l, M);
    check_sparse_initial_coverage(l, M);
    check_high_m_value(M);

    sort(l.begin(), l.end());
    reverse(l.begin(), l.end());
    init_seg();
    update(0, 0);
    for (long long t = 1; t <= M; t++) {
        long long x = getminimum(t - 1, N_);
        if (t != 1) {
            update(t, x + 1);
        }
        for (long long i = 0; i < (N); i++) {
            if (t > l[i].first - l[i].second && t != 1) break;
            if (t >= l[i].first - l[i].second) {
                update(l[i].first + l[i].second, x);
            } else {
                update(l[i].first * 2 - t, x + l[i].first - l[i].second - t);
            }
        }
    }
    long long ans = getminimum(M, N_);
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}