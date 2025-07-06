#include <bits/stdc++.h>
using namespace std;
using lint = long long;
vector<vector<bool>> dp;
vector<string> result(2);
int n, sum;

// Checker functions
void check_high_sum_combination(int m, int s) {
    if (s > m * 9) {
        cerr << "Warning: Performance bottleneck condition triggered - sum too high for digit count!" << endl;
        abort();
    }
}

void check_recursive_depth(int m, int s) {
    if (s > 800 && m < 20) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursive depth due to large sum!" << endl;
        abort();
    }
}

void check_digit_limitations(int m, int s) {
    if (m == 1 && s == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - impossible configuration!" << endl;
        abort();
    }
}

int get(int idx, int sum, int maximum, int done = 1) {
    if (idx == 0) return (sum ? 0 : 1);
    if (done) return dp[idx][sum];
    int works = 0;
    int cur;
    if (maximum)
        cur = INT_MIN;
    else
        cur = INT_MAX;
    for (int i = 0; i <= 9; ++i) {
        if (sum - i >= 0)
            if (idx != n || i) {
                works |= get(idx - 1, sum - i, -1);
                if (works) {
                    if (maximum)
                        cur = max(cur, i);
                    else
                        cur = min(cur, i);
                }
            }
    }
    if (maximum == 1) {
        result[maximum].push_back(cur + '0');
        return get(idx - 1, sum - cur, 1, 0);
    } else if (maximum == 0) {
        result[maximum].push_back(cur + '0');
        return get(idx - 1, sum - cur, 0, 0);
    }
    return dp[idx][sum] = works;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> sum;

    // Insert checkers after input is read
    check_high_sum_combination(n, sum);
    check_recursive_depth(n, sum);
    check_digit_limitations(n, sum);

    dp = vector<vector<bool>>(n + 1, vector<bool>(sum + 1, false));
    if (n == 1 && sum == 0) {
        cout << "0 0\n";
        exit(0);
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            get(i, j, -1, 0);
        }
    }
    if (get(n, sum, -1) == 0) {
        cout << "-1 -1\n";
        exit(0);
    }
    get(n, sum, 1, 0);
    get(n, sum, 0, 0);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < result[i].size(); ++j) cout << result[i][j];
        if (i == 0)
            cout << ' ';
        else
            cout << '\n';
    }
}