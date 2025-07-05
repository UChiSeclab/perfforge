#include <bits/stdc++.h>
using namespace std;

// Checker function for large differences
void check_large_difference_invariant(const vector<long long>& diff) {
    for (const auto& d : diff) {
        if (d > 1e9) { // Large difference threshold
            cerr << "Warning: Performance bottleneck due to large difference between points!" << endl;
            abort();
        }
    }
}

// Checker function for nested iterations with high-difference divisors
void check_nested_iterations_invariant(const vector<long long>& temp) {
    if (temp.size() > 1000) { // Threshold for number of divisors
        cerr << "Warning: Performance bottleneck due to large number of divisors!" << endl;
        abort();
    }
}

// Checker function for frequent divisor calculations on large ranges
void check_frequent_divisor_calculation_invariant(long long n) {
    if (n > 1e9) { // Large range threshold for divisor calculations
        cerr << "Warning: Performance bottleneck due to frequent divisor calculations on large ranges!" << endl;
        abort();
    }
}

vector<long long> divisors(long long n) {
    vector<long long> res;
    for (long long i = 1; i * i <= n; i++) {
        long long one = i;
        if (n % one == 0) {
            res.push_back(one);
            if (one != n / one) res.push_back(n / one);
        }
    }
    for (long long i = 0; i < res.size(); i++) {
        res[i]--;
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> diff;
    for (long long i = 0; i < (long long)a.size() - 1; i++) {
        diff.push_back(a[i + 1] - a[i] - 1);
    }
    // Check for large differences
    check_large_difference_invariant(diff);

    sort(diff.begin(), diff.end());
    map<long long, long long> res;
    map<long long, long long> cando;
    for (long long i = 0; i < diff.size(); i++) {
        vector<long long> temp = divisors(diff[i] + 1);
        // Check for extensive nested iterations
        check_nested_iterations_invariant(temp);

        for (long long j = 0; j < temp.size(); j++) {
            long long pp = (diff[i] - temp[j]) / (temp[j] + 1);
            res[pp] += temp[j];
            cando[pp]++;
        }
    }

    long long ans = 1e12;
    for (auto x : res) {
        if (cando[x.first] == diff.size()) ans = min(ans, x.second);
    }
    cout << ans << '\n';
    return 0;
}