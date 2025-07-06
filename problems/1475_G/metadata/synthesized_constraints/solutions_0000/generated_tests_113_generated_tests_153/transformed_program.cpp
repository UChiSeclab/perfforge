#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int dp[N];

// Checkers for performance bottlenecks
void check_nested_loop_invariant(int n, const vector<int>& v) {
    int unique_count = set<int>(v.begin(), v.end()).size();
    if (n > 1000 && unique_count < n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - nested loop may iterate excessively!" << endl;
        abort();
    }
}

void check_dense_multiples_invariant(const map<int, int>& mp) {
    for (const auto& pair : mp) {
        if (pair.second > 100) {
            cerr << "Warning: Performance bottleneck condition triggered - high density of multiples in input!" << endl;
            abort();
        }
    }
}

void check_sparse_unique_values_invariant(int n, const map<int, int>& mp) {
    int max_frequency = 0;
    for (const auto& pair : mp) {
        max_frequency = max(max_frequency, pair.second);
    }
    if (n > 1000 && max_frequency > n / 5) {
        cerr << "Warning: Performance bottleneck condition triggered - few unique values with many multiples!" << endl;
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
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            mp[v[i]]++;
        }

        // Performance Checker Invocations
        check_nested_loop_invariant(n, v);
        check_dense_multiples_invariant(mp);
        check_sparse_unique_values_invariant(n, mp);

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