#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void check_high_iteration_invariant(int distinctCount, int n) {
    if (distinctCount > n / 2) {
        cerr << "Warning: High iteration count due to numerous distinct element divisors!" << endl;
        abort();
    }
}

void check_repeated_search_invariant(int searchCount, int threshold) {
    if (searchCount > threshold) {
        cerr << "Warning: Repeated binary search on potentially large ranges!" << endl;
        abort();
    }
}

void check_high_frequency_invariant(int maxFrequency, int n) {
    if (maxFrequency > n / 2) {
        cerr << "Warning: High frequency of a common element causing repeated checks!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll a[n];
    unordered_map<ll, ll> frequency;
    ll totalPower = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        frequency[a[i]]++;
        totalPower += a[i];
    }
    sort(a, a + n);

    // Calculate distinct elements and maximum frequency
    int distinctCount = frequency.size();
    int maxFrequency = 0;
    for (const auto& pair : frequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
        }
    }

    // Check for high frequency
    check_high_frequency_invariant(maxFrequency, n);

    ll ans = 0;
    if (a[0] == 1) {
        cout << totalPower;
        return 0;
    }

    int searchCount = 0;
    for (ll i = 2; i <= 200000; i++) {
        if (frequency[i]) {
            ll k = 0;
            for (ll j = i; j <= 200000; j += i) {
                ll it = lower_bound(a, a + n, j) - a;
                ll it1 = lower_bound(a, a + n, j + i) - a;
                k += (it1 - it) * j;
                searchCount++;  // Increment search count
            }
            ans = max(ans, k);
        }
    }

    // Check for excessive search count
    check_repeated_search_invariant(searchCount, 100000); // Threshold of 100,000 searches

    // Check for high iteration count
    check_high_iteration_invariant(distinctCount, n);

    cout << ans;
}