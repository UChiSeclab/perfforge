#include <bits/stdc++.h>
using namespace std;

const long long N = 200005, INF = 2000000000000000000;
long double pi = 3.1415926535897932, minn = 1e-11;

// Invariant checkers

// Check for high variability among energy levels
void check_variability_invariant(const vector<long double>& ar, long double threshold) {
    long double minEnergy = *min_element(ar.begin(), ar.end());
    long double maxEnergy = *max_element(ar.begin(), ar.end());

    if (maxEnergy - minEnergy > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - high variability among energy levels!" << endl;
        abort();
    }
}

// Check for large number of accumulators
void check_accumulator_size_invariant(long long n, long long threshold) {
    if (n > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of accumulators!" << endl;
        abort();
    }
}

// Check for high energy loss percentage
void check_energy_loss_invariant(long double k, long double threshold) {
    if (k > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - high energy loss percentage!" << endl;
        abort();
    }
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(std::numeric_limits<double>::max_digits10);
    
    long long n;
    long double k, ans = 0;
    cin >> n >> k;

    // Check for large number of accumulators
    check_accumulator_size_invariant(n, 9000); // Threshold set close to upper limit

    vector<long double> ar(n);
    for (long long i = 0; i < n; i++) cin >> ar[i];

    // Check for high variability among energy levels
    check_variability_invariant(ar, 800); // Arbitrary threshold for variability

    // Check for high energy loss percentage
    check_energy_loss_invariant(k, 90); // High threshold for energy loss percentage

    long double l = 0, r = 1000.0;
    while ((r - l) > minn) {
        long double m = (l + r) / 2.0;
        map<long double, long long> mp;
        for (long long i = 0; i < n; i++) mp[ar[i]]++;
        long long f = 0;
        while (mp.size()) {
            auto it = mp.begin();
            long double cu = (*it).first;
            it = mp.end();
            it--;
            long double last = (*it).first;
            if (cu >= m) break;
            long double req = (100.0 * (m - cu)) / (100.0 - k);
            auto itr = mp.lower_bound(req + m);
            if (itr == mp.end()) {
                if (last <= m) {
                    f = 1;
                    break;
                }
                long double g = last - m;
                mp[last]--;
                if (mp[last] == 0) mp.erase(last);
                mp[cu]--;
                if (mp[cu] == 0) mp.erase(cu);
                mp[cu + (g * ((100.0 - k) / 100.0))]++;
            } else {
                long double fin = (*itr).first;
                mp[fin]--;
                if (mp[fin] == 0) mp.erase(fin);
                mp[fin - req]++;
                mp[cu]--;
                if (mp[cu] == 0) mp.erase(cu);
            }
        }
        if (f == 0) {
            ans = m;
            l = m;
        } else
            r = m;
    }
    cout << ans;
}