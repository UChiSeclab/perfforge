#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int dp[N];

// Check for small numbers with high frequency
void check_small_frequent_numbers(const map<int, int>& mp) {
    int threshold = 10; // Arbitrary threshold for high frequency small values
    for (const auto& entry : mp) {
        if (entry.first <= 10 && entry.second > threshold) {
            cerr << "Warning: Performance bottleneck condition triggered - small numbers with high frequency!" << endl;
            abort();
        }
    }
}

// Check for high multiplicity of small values
void check_multiplicity(const vector<int>& v) {
    int small_value_limit = 10; // Threshold for what constitutes a "small" value
    int count_of_small_values = 0;
    for (int value : v) {
        if (value <= small_value_limit) {
            count_of_small_values++;
        }
    }
    if (count_of_small_values > v.size() / 2) { // Arbitrary condition for too many small values
        cerr << "Warning: Performance bottleneck condition triggered - high multiplicity of small values!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int> mp;
        set<int> st;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            st.insert(v[i]);
            mp[v[i]]++;
        }

        // Integrate checks
        check_small_frequent_numbers(mp); // Check 1
        check_multiplicity(v); // Check 2

        sort(v.begin(), v.end());
        for (int i = v.size() - 1; i >= 0;) {
            dp[v[i]] = mp[v[i]];
            for (int j = 2 * v[i]; j < N; j += v[i]) {
                dp[v[i]] = max(dp[j] + mp[v[i]], dp[v[i]]);
            }
            i = i - mp[v[i]];
        }
        int mx = 0;
        for (int i = 0; i < N; i++) {
            mx = max(mx, dp[i]);
        }
        cout << n - mx << endl;
        for (int i = 0; i <= v[n - 1]; i++) {
            dp[i] = 0;
        }
    }
    return 0;
}