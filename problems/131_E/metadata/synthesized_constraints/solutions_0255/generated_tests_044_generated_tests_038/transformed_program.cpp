#include <bits/stdc++.h>
using namespace std;
const int MAX = 100007;
const int MOD = 1000000007;

// Checkers integrated as functions
void check_shared_line_invariant(int line_size, int threshold) {
    if (line_size > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - too many queens on the same line or diagonal!" << endl;
        abort();
    }
}
void check_repeated_checks_invariant(int operations, int threshold) {
    if (operations > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated traversal and checks!" << endl;
        abort();
    }
}
void check_diagonal_complexity_invariant(int diagonal_count, int threshold) {
    if (diagonal_count > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - complex diagonal calculations!" << endl;
        abort();
    }
}
void check_sparse_configuration_invariant(int m, int n, double density_threshold) {
    double density = static_cast<double>(m) / (n * n);
    if (density > density_threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - dense configuration of queens!" << endl;
        abort();
    }
}

void solve() {
    pair<int, int> a[MAX];
    int n, m;
    cin >> n >> m;

    // Check for sparse vs. dense configuration
    check_sparse_configuration_invariant(m, n, 0.01);

    map<int, vector<pair<int, int>>> row, col, dr, ur;
    map<pair<int, int>, int> mp;

    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
        row[a[i].second].push_back(a[i]);
        col[a[i].first].push_back(a[i]);
        dr[a[i].first - a[i].second].push_back(a[i]);
        ur[a[i].first + a[i].second].push_back(a[i]);
    }

    for (int i = 1; i <= n; i++) {
        vector<pair<int, int>> curr = row[i];
        int mn = n + 7, mx = -1;
        if (curr.size() <= 1) {
            continue;
        }

        // Check for shared lines
        check_shared_line_invariant(curr.size(), 10);

        for (pair<int, int> p : curr) {
            mn = min(mn, p.first);
            mx = max(mx, p.first);
        }
        for (pair<int, int> p : curr) {
            if (p.first == mn || p.first == mx) {
                mp[p]++;
            } else {
                mp[p] += 2;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        vector<pair<int, int>> curr = col[i];
        int mn = n + 7, mx = -1;
        if (curr.size() <= 1) {
            continue;
        }

        // Check for shared columns
        check_shared_line_invariant(curr.size(), 10);

        for (pair<int, int> p : curr) {
            mn = min(mn, p.second);
            mx = max(mx, p.second);
        }
        for (pair<int, int> p : curr) {
            if (p.second == mn || p.second == mx) {
                mp[p]++;
            } else {
                mp[p] += 2;
            }
        }
    }

    int diagonal_operations = 0;

    for (int i = 1 - n; i <= n - 1; i++) {
        vector<pair<int, int>> curr = dr[i];
        int mn = n + 7, mx = -n - 7;
        if (curr.size() <= 1) {
            continue;
        }

        // Track diagonal operations
        diagonal_operations += curr.size();

        for (pair<int, int> p : curr) {
            mn = min(mn, p.first);
            mx = max(mx, p.first);
        }
        for (pair<int, int> p : curr) {
            if (p.first == mn || p.first == mx) {
                mp[p]++;
            } else {
                mp[p] += 2;
            }
        }
    }

    for (int i = 1 + 1; i <= n + n; i++) {
        vector<pair<int, int>> curr = ur[i];
        int mn = n + 7, mx = -n - 7;
        if (curr.size() <= 1) {
            continue;
        }

        // Track diagonal operations
        diagonal_operations += curr.size();

        for (pair<int, int> p : curr) {
            mn = min(mn, p.first);
            mx = max(mx, p.first);
        }
        for (pair<int, int> p : curr) {
            if (p.first == mn || p.first == mx) {
                mp[p]++;
            } else {
                mp[p] += 2;
            }
        }
    }

    // Check for diagonal complexity
    check_diagonal_complexity_invariant(diagonal_operations, 100);

    int cnt[9] = {};
    for (int i = 0; i < m; i++) {
        cnt[mp[a[i]]]++;
    }
    for (int i = 0; i <= 8; i++) {
        cout << cnt[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}