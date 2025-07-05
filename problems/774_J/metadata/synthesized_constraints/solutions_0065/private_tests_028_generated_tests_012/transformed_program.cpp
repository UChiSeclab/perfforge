#include <bits/stdc++.h>
using namespace std;

int dp[1000];
int here[1000][1000];

void check_nested_loop_with_unknowns(int n, int countUnknowns, int k) {
    if (countUnknowns > n / 2 && k < 3) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive nested loop executions due to many unknowns." << endl;
        abort();
    }
}

void check_high_iterative_complexity(int n, int k) {
    if (n >= 90 && k < n / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high iterative complexity due to large n and small k." << endl;
        abort();
    }
}

void check_redundant_checks_small_k(int countUnknowns, int k) {
    if (countUnknowns > 0 && k < 2) {
        cerr << "Warning: Performance bottleneck condition triggered - redundant checks with small k." << endl;
        abort();
    }
}

int solve(string s) {
    memset(dp, 0, sizeof(dp));
    dp[0] = (s[0] == 'N');
    for (int i = 1; i < int(s.size()); ++i) {
        if (s[i] != 'N')
            dp[i] = 0;
        else
            dp[i] = dp[i - 1] + 1;
    }
    int mx = 0;
    for (int i = 0; i < int(s.size()); ++i) mx = max(mx, dp[i]);
    return mx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // Count the number of '?'
    int countUnknowns = count(s.begin(), s.end(), '?');

    // Insert performance checks before major computation
    check_nested_loop_with_unknowns(n, countUnknowns, k);
    check_high_iterative_complexity(n, k);
    check_redundant_checks_small_k(countUnknowns, k);

    int mn = solve(s);
    if (k < mn) {
        cout << "NO" << endl;
        return 0;
    }
    if (k == 0) {
        cout << "YES" << endl;
        return 0;
    }
    bool find = false;
    s.push_back('Y');
    for (int i = 0; i < n; ++i)
        for (int tam = 1; tam < i + 2; ++tam) {
            if (s[i + 1] == 'N') continue;
            here[i][tam] = true;
            for (int j = i - tam + 1; j < i + 1; ++j)
                if (s[j] == 'Y') here[i][tam] = false;
            if (i - tam >= 0 && s[i - tam] == 'N') here[i][tam] = false;
            if (tam == k && here[i][tam]) find = true;
        }
    if (find)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}