#include <bits/stdc++.h>
using namespace std;
int n;
long long m, b, MOD, a[555], dp[555][555], temp[555][555];

// Checkers for performance bottlenecks
void check_line_bug_constraint(int m, int b) {
    if (m > 450 && b < 50) {  // Arbitrary thresholds based on invariant
        cerr << "Warning: Performance bottleneck condition triggered - high line count with tight bug constraint!" << endl;
        abort();
    }
}

void check_bug_variability(const vector<int>& a, int b) {
    int max_variability = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
    if (max_variability > 400 && accumulate(a.begin(), a.end(), 0) / a.size() > b / 2) {  // Example conditions
        cerr << "Warning: Performance bottleneck condition triggered - high bug per line variability!" << endl;
        abort();
    }
}

void check_programmer_count_constraint(int n, int b) {
    if (n > 50 && b < 250) {  // Example threshold values
        cerr << "Warning: Performance bottleneck condition triggered - large programmer count with moderate bug limits!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> b >> MOD;
    vector<int> a(n);
    for (int(i) = (1); (i) <= (n); i++) cin >> a[i];
    
    // Insert performance-checking functions
    check_line_bug_constraint(m, b); // Check for high line count with tight bug constraint
    check_bug_variability(a, b); // Check for high bug per line variability
    check_programmer_count_constraint(n, b); // Check for large programmer count with moderate bug limits

    dp[0][0] = 1LL;
    for (int(i) = (1); (i) <= (m); i++) {
        memset(temp, 0, sizeof(temp));
        for (int(j) = (0); (j) <= (b); j++) {
            long long res = 0LL;
            int l = i == 1 ? 0 : 1;
            for (int(k) = (l); (k) <= (n); k++) {
                res += dp[k][j];
                if (j + a[k] <= b) temp[k][j + a[k]] += res % MOD;
            }
        }
        memcpy(dp, temp, sizeof(temp));
    }
    long long ans = 0LL;
    for (int(i) = (1); (i) <= (n); i++)
        for (int(j) = (0); (j) <= (b); j++) ans = (ans + dp[i][j]) % MOD;
    cout << ans % MOD << '\n';
    return 0;
}