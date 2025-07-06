#include <bits/stdc++.h>
using namespace std;

// Function to check high density of possible overlaps
void check_overlap_invariant(long long l, long long r, long long p, long long q) {
    if ((r - l > 800) && (p > 45) && (q > 45)) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive overlap checks likely!" << endl;
        abort();
    }
}

// Function to check large number of online periods
void check_interval_count_invariant(long long p, long long q) {
    if ((p > 45) || (q > 45)) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of online periods!" << endl;
        abort();
    }
}

// Function to check extensive iteration for overlap checking
void check_iteration_invariant(long long l, long long r, size_t c_size) {
    if ((r - l > 800) && (c_size > 900)) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iteration expected!" << endl;
        abort();
    }
}

void solve() {
    long long p, q, l, r;
    cin >> p >> q >> l >> r;

    // Check the invariants after reading input
    check_overlap_invariant(l, r, p, q);
    check_interval_count_invariant(p, q);

    vector<long long> v(2000 + 7, 0);
    for (long long i = 0; i < p; i++) {
        long long f, s;
        cin >> f >> s;
        for (long long j = f; j <= s; j++) {
            v[j] = 1;
        }
    }
    vector<long long> c;
    for (long long i = 0; i < q; i++) {
        long long f, s;
        cin >> f >> s;
        for (__typeof(s + 1) j = (f) - ((f) > (s + 1));
             j != (s + 1) - ((f) > (s + 1)); j += 1 - 2 * ((f) > (s + 1))) {
            c.push_back(j);
        }
    }

    // Check the iteration invariant before executing the main loop
    check_iteration_invariant(l, r, c.size());

    long long ans = 0;
    for (long long i = l; i <= r; i++) {
        for (auto x : c) {
            if (v[x + i]) {
                ans++;
                break;
            }
        }
    }
    cout << ans << '\n';
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t;
    t = 1;
    while (t--) solve();
    return 0;
}