#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_variability_invariant(long long n, const vector<long long>& a) {
    long long max_a = *max_element(a.begin(), a.end());
    long long min_a = *min_element(a.begin(), a.end());
    if (n > 10000 && (max_a - min_a > max_a / 2)) {
        cerr << "Warning: Performance bottleneck condition triggered - high variability in stack heights!" << endl;
        abort();
    }
}

void check_sum_invariant(long long sum, long long n) {
    if (sum > 10 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - high total sum of block heights!" << endl;
        abort();
    }
}

void check_sorting_invariant(long long n) {
    if (n > 50000) {
        cerr << "Warning: Performance bottleneck condition triggered - dense setup requiring frequent sorting!" << endl;
        abort();
    }
}

void check_critical_height_invariant(const vector<long long>& a, long long m) {
    for (auto height : a) {
        if (height > m * 0.9) {
            cerr << "Warning: Performance bottleneck condition triggered - stacks approaching critical height threshold!" << endl;
            abort();
        }
    }
}

int32_t main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long int n, m, sum = 0, ans = 0;
    cin >> n >> m;
    vector<long long int> a(n + 1);
    for (long long int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    check_sum_invariant(sum, n);  // Check for high initial sum of block heights
    check_critical_height_invariant(a, m);  // Check for critical height thresholds

    a[0] = 1;
    if (n == 1 || sum == n) {
        cout << 0;
        return 0;
    }

    sort(a.begin(), a.end());
    check_sorting_invariant(n);  // Check for dense setup requiring frequent sorting

    check_variability_invariant(n, a);  // Check for high variability in stack heights

    long long int th = a[n];
    for (long long int i = n - 1; i >= 0; i--) {
        if (i == 0)
            ans += th;
        else if (a[i + 1] == 1 || a[i] >= th - 1) {
            ans++;
            th = max(1LL, th - 1);
        } else {
            ans += th - a[i];
            th = a[i];
        }
        cerr << sum - ans << " ";
    }
    cerr << '\n';
    cout << sum - ans;
}