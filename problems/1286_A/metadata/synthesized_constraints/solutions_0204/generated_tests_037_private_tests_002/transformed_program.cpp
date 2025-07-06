#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_zero_count(const vector<int>& p, int n) {
    int zero_count = count(p.begin(), p.end(), 0);
    if (zero_count > n / 2) { // More than half of the bulbs are removed
        cerr << "Warning: High zero count invariant triggered - too many removed bulbs!" << endl;
        abort();
    }
}

void check_input_size_and_complexity(int n, const vector<int>& p) {
    int zero_count = count(p.begin(), p.end(), 0);
    if (n == 100 && zero_count > n / 2) {
        cerr << "Warning: Input size and complexity invariant triggered - maximum input size with many zeros!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);

    int n;
    cin >> n;
    vector<int> p(n);
    
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // Insert performance invariant checks
    check_high_zero_count(p, n); // Check for high number of zeroes
    check_input_size_and_complexity(n, p); // Check for large input and complexity

    int impar = (n + 1) / 2, par = n / 2;
    for (int i = 0; i < n; i++) {
        if (p[i] > 0) {
            if (p[i] % 2 == 0)
                par--;
            else
                impar--;
        }
    }

    const int inf = 1000;
    vector<vector<vector<vector<int>>>> dp(
        n + 1, vector<vector<vector<int>>>(
                   n, vector<vector<int>>(n, vector<int>(2, inf))));
    
    if (p[0] > 0) {
        if (p[0] % 2 == 0)
            dp[0][par][impar][0] = 0;
        else
            dp[0][par][impar][1] = 0;
    } else {
        if (par > 0) dp[0][par - 1][impar][0] = 0;
        if (impar > 0) dp[0][par][impar - 1][1] = 0;
    }

    for (int i = 1; i < n; i++) {
        for (int ppar = 0; ppar <= par; ppar++) {
            for (int ip = 0; ip <= impar; ip++) {
                if (p[i] > 0) {
                    if (p[i] % 2 == 0)
                        dp[i][ppar][ip][0] =
                            min(dp[i - 1][ppar][ip][1] + 1, dp[i - 1][ppar][ip][0]);
                    else
                        dp[i][ppar][ip][1] =
                            min(dp[i - 1][ppar][ip][0] + 1, dp[i - 1][ppar][ip][1]);
                } else {
                    if (ppar > 0)
                        dp[i][ppar - 1][ip][0] =
                            min(dp[i - 1][ppar][ip][1] + 1, dp[i - 1][ppar][ip][0]);
                    if (ip > 0)
                        dp[i][ppar][ip - 1][1] =
                            min(dp[i - 1][ppar][ip][0] + 1, dp[i - 1][ppar][ip][1]);
                }
            }
        }
    }
    
    cout << min(dp[n - 1][0][0][0], dp[n - 1][0][0][1]) << endl;
}