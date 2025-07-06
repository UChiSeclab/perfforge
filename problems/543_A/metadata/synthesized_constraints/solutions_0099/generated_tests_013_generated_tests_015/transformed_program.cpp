#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mx = 500 + 9;
ll MOD = 1;
int a[mx];
ll dp[mx][mx], then[mx][mx];

// Checker functions
void check_bug_allowance_invariant(int b, const vector<int>& bugs) {
    int totalBugs = accumulate(bugs.begin(), bugs.end(), 0);
    if (b > totalBugs / 2) {
        cerr << "Warning: High bug allowance may lead to increased computation!" << endl;
        abort();
    }
}

void check_line_combination_invariant(int m, int b) {
    if (m > 400 && b > 300) {
        cerr << "Warning: Extensive line combinations due to high m and b!" << endl;
        abort();
    }
}

void check_programmer_count_invariant(int n, const vector<int>& bugs) {
    int diverseBugRates = set<int>(bugs.begin(), bugs.end()).size();
    if (n > 450 && diverseBugRates > n / 2) {
        cerr << "Warning: High programmer count and diverse bug rates!" << endl;
        abort();
    }
}

void check_dynamic_structure_invariant(int b) {
    if (b > 400) {
        cerr << "Warning: Large bug threshold may lead to frequent dynamic structure updates!" << endl;
        abort();
    }
}

int main() {
    int n, m, b;
    scanf("%d %d %d %lld", &n, &m, &b, &MOD);

    vector<int> bugs(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        bugs[i-1] = a[i];
    }

    // Check performance invariants
    check_bug_allowance_invariant(b, bugs);
    check_line_combination_invariant(m, b);
    check_programmer_count_invariant(n, bugs);
    check_dynamic_structure_invariant(b);

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= b; k++) {
            then[i][k] = 1;
        }
    }

    for (int j = m - 1; j >= 0; j--) {
        for (int k = 0; k <= b; k++) {
            for (int i = n; i >= 1; i--) {
                dp[i][k] = dp[i + 1][k];
                if (k + a[i] <= b) dp[i][k] += then[i][k + a[i]];
                if (dp[i][k] >= MOD) dp[i][k] %= MOD;
            }
        }
        for (int k = 0; k <= b; k++) {
            for (int i = n; i >= 1; i--) {
                then[i][k] = dp[i][k];
                dp[i][k] = 0;
            }
        }
    }
    ll ans = then[1][0];
    printf("%lld\n", ans);
}