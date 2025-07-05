#include <bits/stdc++.h>
using namespace std;

int arr[] = {1, 2, 3, 4, 5, 0};
vector<vector<long long>> dp;
bool vis[8];
unordered_map<int, int> mp;
set<pair<int, int>> s;

void dfs(int i) {
    vis[i] = true;
    for (int k : dp[i]) {
        if (!vis[k]) {
            dfs(k);
        }
    }
}

// Checkers for performance invariants
void check_permutation_invariant(int n, int m) {
    if (n == 7 && m > 15) {
        cerr << "Warning: Permutation and edge density invariant triggered - computational overhead expected!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int n) {
    if (n == 7) {
        cerr << "Warning: Nested loop invariant triggered - potential high computational cost!" << endl;
        abort();
    }
}

void check_set_operation_invariant(int maxPermutations, int edgeCount) {
    if (maxPermutations > 500 && edgeCount > 10) {
        cerr << "Warning: Set operation invariant triggered - heavy use of set operations expected!" << endl;
        abort();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    dp.resize(n);
    for (long long i = 0; i < m; i++) {
        int xx, yy;
        cin >> xx >> yy;
        --xx;
        --yy;
        dp[xx].push_back(yy);
        dp[yy].push_back(xx);
    }

    // Apply performance checkers
    check_permutation_invariant(n, m);
    check_nested_loop_invariant(n);

    if (n < 7) {
        cout << m << endl;
        exit(0);
    }

    int mini = 10;
    int maxi = 0;
    for (long long i = 0; i < n; i++) {
        mini = min(mini, (int)dp[i].size());
        maxi = max(maxi, (int)dp[i].size());
    }

    memset(vis, false, sizeof vis);
    dfs(0);
    
    bool ff = false;
    for (long long i = 0; i < n; i++) {
        if (!vis[i]) {
            ff = true;
        }
    }
    if (ff) {
        cout << m << endl;
        exit(0);
    }

    int ans = 0;
    int maxPermutations = 0;
    do {
        maxPermutations++; // Count permutations to check the invariant
        for (long long i = 1; i < n; i++) {
            mp[i] = arr[i - 1];
            for (long long j = 0; j < 6; j++) {
                mp[0] = j;
                for (long long k = 0; k < 7; k++) {
                    vis[k] = false;
                }
                s.clear();
                for (long long ii = 0; ii < n; ii++) {
                    for (long long jj = 0; jj < dp[ii].size(); jj++) {
                        int xx = min(mp[ii], mp[dp[ii][jj]]);
                        int yy = max(mp[ii], mp[dp[ii][jj]]);
                        s.insert(make_pair(xx, yy));
                    }
                }
                ans = max(ans, (int)s.size());
            }
        }
    } while (next_permutation(arr, arr + 6));

    // Apply checker after permutation processing
    check_set_operation_invariant(maxPermutations, m);

    cout << ans << endl;
}