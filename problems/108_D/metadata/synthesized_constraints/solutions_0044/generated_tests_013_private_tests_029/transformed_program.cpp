#include <bits/stdc++.h>
using namespace std;

// Checker for nested loops invariant
void check_nested_loops_invariant(int n, int m) {
    if (m > 500 && n > 90) {
        cerr << "Warning: High iteration count due to nested loops!" << endl;
        abort();
    }
}

// Checker for team size invariant
void check_team_size_invariant(int sum, int n) {
    if (sum >= n && sum <= n + 10) {
        cerr << "Warning: Inefficient handling of large teams!" << endl;
        abort();
    }
}

// Checker for combinatorial explosion invariant
void check_combinatorial_explosion_invariant(const vector<int>& s) {
    int variance_threshold = 50;
    int min_val = *min_element(s.begin(), s.end());
    int max_val = *max_element(s.begin(), s.end());
    if (max_val - min_val > variance_threshold) {
        cerr << "Warning: Combinatorial explosion due to uneven distribution!" << endl;
        abort();
    }
}

// Checker for normalization overhead invariant
void check_normalization_invariant(int n) {
    if (n > 90) {
        cerr << "Warning: High normalization overhead!" << endl;
        abort();
    }
}

int main() {
    int n, m, h;
    cin >> n >> m >> h;
    
    int sum = 0;
    vector<int> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
        sum += s[i];
    }
    
    // Perform checks after input
    check_nested_loops_invariant(n, m);
    check_team_size_invariant(sum, n);
    check_combinatorial_explosion_invariant(s);
    check_normalization_invariant(n);
    
    s[h - 1]--;
    if (sum < n || s[h - 1] < 0) {
        cout << -1.0 << endl;
        return 0;
    }
    
    vector<vector<double>> comb(101, vector<double>(101, 0.0));
    for (int i = 0; i <= 100; i++) {
        comb[i][0] = 1.0;
        for (int j = 1; j <= i && j <= 100; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
    
    vector<double> dp(n, 0.0), dpp(n, 0.0);
    dp[0] = dpp[0] = 1.0;
    for (int i = 0; i < m; i++) {
        vector<double> dp2(n, 0.0), dpp2(n, 0.0);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= s[i] && j + k < n; k++) {
                dp2[j + k] += dp[j] * comb[s[i]][k];
                dpp2[j + k] += dpp[j] * comb[s[i]][k];
            }
        }
        dp.swap(dp2);
        if (i != h - 1) {
            dpp.swap(dpp2);
        }
        double mm = *max_element(dp.begin(), dp.end());
        for (int j = 0; j < dp.size(); j++) {
            dp[j] /= mm;
            dpp[j] /= mm;
        }
    }
    
    printf("%.10f\n", 1.0 - (dpp.back() / dp.back()));
    return 0;
}