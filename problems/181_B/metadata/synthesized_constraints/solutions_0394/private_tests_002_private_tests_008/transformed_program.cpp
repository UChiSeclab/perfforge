#include <bits/stdc++.h>
using namespace std;

// Checker for nested loop complexity
void check_nested_loop_invariant(long long n) {
    if (n > 2500) {
        cerr << "Warning: nested_loop_invariant triggered - potential O(n^2) performance bottleneck" << endl;
        abort();
    }
}

// Checker for midpoint calculation and lookup
void check_midpoint_lookup_invariant(long long potentialMidpoints, long long n) {
    if (potentialMidpoints > n * (n - 1) / 4) {
        cerr << "Warning: midpoint_lookup_invariant triggered - excessive midpoints being checked" << endl;
        abort();
    }
}

int main() {
    long long n, i, j;
    cin >> n;

    // Check for potential performance bottlenecks based on input size
    check_nested_loop_invariant(n);

    vector<pair<double, double>> v(n);
    map<pair<double, double>, long long> mp;
    for (i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        mp[{a, b}] = i;
        v[i] = {a, b};
    }

    long long ans = 0;
    long long potentialMidpoints = 0;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            double a = (v[i].first + v[j].first) / 2.0;
            double b = (v[i].second + v[j].second) / 2.0;
            potentialMidpoints++;
            if (mp.find({a, b}) != mp.end()) {
                long long c = mp[{a, b}];
                if (c != i && c != j) ans++;
            }
        }
    }

    // Check for excessive midpoint calculations
    check_midpoint_lookup_invariant(potentialMidpoints, n);

    cout << ans;
    return 0;
}