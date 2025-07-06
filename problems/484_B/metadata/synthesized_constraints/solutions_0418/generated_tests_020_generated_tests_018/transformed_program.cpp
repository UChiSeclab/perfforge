#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
long long has[N];

void check_active_multiples_invariant(const vector<long long>& has, long long threshold) {
    long long active_multiples = 0;
    for (long long i = 1; i <= N; ++i) {
        if (has[i]) {
            ++active_multiples;
        }
    }
    if (active_multiples > threshold) {
        cerr << "Warning: active_multiples_invariant triggered - too many active multiples!" << endl;
        abort();
    }
}

void check_dense_distribution_invariant(const vector<long long>& s, long long threshold) {
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] - s[i - 1] < threshold) {
            cerr << "Warning: dense_distribution_invariant triggered - values too densely packed!" << endl;
            abort();
        }
    }
}

void check_small_divisors_invariant(const vector<long long>& has, long long small_threshold, long long count_threshold) {
    long long count = 0;
    for (long long i = 1; i <= small_threshold; ++i) {
        if (has[i]) {
            ++count;
        }
    }
    if (count > count_threshold) {
        cerr << "Warning: small_divisors_invariant triggered - too many small divisors!" << endl;
        abort();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, a;
    cin >> n;
    vector<long long> s;
    for (long long i = 0; i < n; i++) {
        cin >> a;
        has[a] = 1;
        s.push_back(a);
    }
    sort(s.begin(), s.end());

    // Inserted checks
    check_active_multiples_invariant(vector<long long>(begin(has), end(has)), /* threshold */ 100); // Example threshold
    check_dense_distribution_invariant(s, /* threshold */ 1); // Example threshold
    check_small_divisors_invariant(vector<long long>(begin(has), end(has)), /* small_threshold */ 100, /* count_threshold */ 10); // Example thresholds

    long long ans = 0;
    for (long long i = 1; i <= N; i++) {
        if (has[i])
            for (long long j = 2 * i; j <= N + i; j += i) {
                auto it = lower_bound(s.begin(), s.end(), j);
                if (it != s.begin()) {
                    it--;
                    ans = max(ans, *it % i);
                }
            }
    }
    cout << ans;
}