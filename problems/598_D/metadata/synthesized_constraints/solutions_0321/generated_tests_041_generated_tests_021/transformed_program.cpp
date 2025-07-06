#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

void check_complex_path_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - complex path exploration!" << endl;
        abort();
    }
}

void check_branching_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high branching factor!" << endl;
        abort();
    }
}

void check_search_space_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large search space!" << endl;
        abort();
    }
}

void find(vector<vector<bool>>& b, int i, int j, int n, int m, int e,
          vector<vector<bool>>& d) {
    dp[i][j] = e;
    d[i][j] = true;
    if (i != 0 && b[i - 1][j] && !d[i - 1][j]) {
        find(b, i - 1, j, n, m, e, d);
    }
    if (i != n - 1 && b[i + 1][j] == true && !d[i + 1][j])
        find(b, i + 1, j, n, m, e, d);
    if (j != 0 && b[i][j - 1] == true && !d[i][j - 1]) {
        find(b, i, j - 1, n, m, e, d);
    }
    if (j != m - 1 && b[i][j + 1] == true && !d[i][j + 1])
        find(b, i, j + 1, n, m, e, d);
}

int helper(vector<vector<char>>& a, int i, int j, int n, int m,
           vector<vector<bool>>& b) {
    int c = 0;
    b[i][j] = true;

    // Check for large search space
    check_search_space_invariant((i > 0 && a[i - 1][j] == '.') &&
                                 (i < n - 1 && a[i + 1][j] == '.') &&
                                 (j > 0 && a[i][j - 1] == '.') &&
                                 (j < m - 1 && a[i][j + 1] == '.'));

    if (i != 0) {
        if (a[i - 1][j] == '*') {
            c = 1;
        } else if (a[i - 1][j] == '.' && b[i - 1][j] == false)
            c = c + helper(a, i - 1, j, n, m, b);
    }
    if (i != n - 1) {
        if (a[i + 1][j] == '*') {
            c++;
        } else if (a[i + 1][j] == '.' && b[i + 1][j] == false)
            c = c + helper(a, i + 1, j, n, m, b);
    }
    if (j != 0) {
        if (a[i][j - 1] == '*') {
            c++;
        } else if (a[i][j - 1] == '.' && b[i][j - 1] == false)
            c = c + helper(a, i, j - 1, n, m, b);
    }
    if (j != m - 1) {
        if (a[i][j + 1] == '*') {
            c++;
        } else if (a[i][j + 1] == '.' && b[i][j + 1] == false)
            c = c + helper(a, i, j + 1, n, m, b);
    }
    return c;
}

int main() {
    vector<vector<char>> a;
    vector<char> v;
    vector<vector<bool>> b, d;
    vector<bool> bb;
    int m, n, k;
    int i, j;
    char e;
    cin >> n >> m >> k;

    // Check for potential expensive computation based on input size
    check_complex_path_invariant(n * m > 900000);  // arbitrary threshold based on 1000x1000 max

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> e;
            v.push_back(e);
            bb.push_back(false);
        }
        a.push_back(v);
        v.clear();
        d.push_back(bb);
        b.push_back(bb);
        bb.clear();
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] == '*')
                dp[i][j] = 0;
            else if (b[i][j] == false) {
                dp[i][j] = helper(a, i, j, n, m, b);

                // Check for high branching factor
                check_branching_invariant(dp[i][j] > 10);  // arbitrary threshold

                find(b, i, j, n, m, dp[i][j], d);
            }
        }
    }

    int f, s;
    for (i = 0; i < k; i++) {
        cin >> f >> s;
        cout << dp[f - 1][s - 1] << "\n";
    }
}