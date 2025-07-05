#include <bits/stdc++.h>
using namespace std;

// Checker function for nested loops
void check_nested_loop_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: nested_loop_invariant triggered - high cost of nested iterations" << endl;
        abort();
    }
}

// Hypothetical function to detect sparse distribution
bool detectSparseDistribution(const vector<long long int> dest[], int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!dest[i].empty()) count++;
    }
    return count < (n / 2);
}

// Checker function for sparse candy distribution
void check_sparse_distribution_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: sparse_distribution_invariant triggered - extensive travel due to sparse candy distribution" << endl;
        abort();
    }
}

// Checker function for station-candy ratio
void check_station_candy_ratio_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: station_candy_ratio_invariant triggered - high station count with few candies" << endl;
        abort();
    }
}

void solve() {
    long long int n, m, u, v;
    cin >> n >> m;

    vector<long long int> dest[n + 1];
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        dest[u].push_back(v);
    }

    // Insert checker for nested loops
    check_nested_loop_invariant(n > 100);

    // Insert checker for sparse candy distribution
    check_sparse_distribution_invariant(detectSparseDistribution(dest, n));

    // Insert checker for station-candy ratio
    check_station_candy_ratio_invariant(n > 2 * m);

    unordered_map<long long int, long long int> opt;
    for (int i = 1; i <= n; i++) {
        for (auto t : dest[i]) {
            long long int temp = t - i;
            if (temp < 0) {
                temp += n;
            }
            if (opt[i] == 0) {
                opt[i] = temp;
            } else {
                opt[i] = min(opt[i], temp);
            }
        }
    }
    vector<long long int> ans;
    for (int i = 1; i <= n; i++) {
        long long int optval = -1;
        for (int j = 1; j <= n; j++) {
            long long int temp = j - i;
            if (temp < 0) {
                temp += n;
            }
            long long int lulz = dest[j].size();
            temp += (lulz - 1) * n + opt[j];
            optval = max(temp, optval);
        }
        ans.push_back(optval);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(50);
    solve();
}