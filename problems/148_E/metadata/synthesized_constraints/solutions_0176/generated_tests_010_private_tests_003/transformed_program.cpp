#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long dp1[101][101][101];
long long dp2[101][10001];
long long ans1[101][101];
long long arr[101][101];
long long sz[101];
long long ind = -1;

void check_large_shelf_invariant(long long shelfSize) {
    if (shelfSize > 75) {  // Assuming 75 is a critical threshold
        cerr << "Warning: Large shelf size may lead to excessive recursion in f1!" << endl;
        abort();
    }
}

void check_memoization_invariant(long long left, long long size) {
    if (left > size / 2) {  // If `left` is large relative to the shelf size
        cerr << "Warning: Ineffective memoization due to high 'left' parameter in f1!" << endl;
        abort();
    }
}

void check_high_left_invariant(long long left) {
    if (left > 7500) {  // Assuming 7500 is a threshold for many combinations
        cerr << "Warning: High 'left' parameter in f2 may cause performance degradation!" << endl;
        abort();
    }
}

void check_excessive_combinations_invariant(long long shelfSize, long long left) {
    if (shelfSize > 50 && left > 5000) {  // If both values are high
        cerr << "Warning: Excessive combinations in f2 due to large shelf size and high 'left'!" << endl;
        abort();
    }
}

long long f1(long long i, long long j, long long left) {
    if (left == 0) return dp1[i][j][left] = 0;
    if (i == j) return arr[ind][i];
    if (dp1[i][j][left] != -1) return dp1[i][j][left];
    
    check_memoization_invariant(left, j - i + 1); // Check for potential memoization issues
    
    dp1[i][j][left] = max(arr[ind][i] + f1(i + 1, j, left - 1),
                          arr[ind][j] + f1(i, j - 1, left - 1));
    return dp1[i][j][left];
}

long long f2(long long i, long long left) {
    check_high_left_invariant(left); // Check for high 'left' parameter
    
    if (i > n) {
        if (left == 0) return 0;
        return -1e18;
    }
    if (dp2[i][left] != -1) return dp2[i][left];
    long long ans = 0;
    for (long long j = 0; j <= min(left, sz[i]); j++) {
        check_excessive_combinations_invariant(sz[i], left); // Check for excessive combinations
        ans = max(ans, f2(i + 1, left - j) + ans1[i][j]);
    }
    return dp2[i][left] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        cin >> sz[i];
        
        check_large_shelf_invariant(sz[i]); // Check for large shelf sizes
        
        for (long long j = 1; j <= sz[i]; j++) cin >> arr[i][j];
    }
    memset(ans1, 0, sizeof(ans1));
    for (long long i = 1; i <= n; i++) {
        memset(dp1, -1, sizeof(dp1));
        for (long long j = 1; j <= sz[i]; j++) {
            ind = i;
            ans1[ind][j] = f1(1, sz[i], j);
        }
    }
    memset(dp2, -1, sizeof(dp2));
    cout << f2(1, m);
}