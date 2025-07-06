#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
long long t[11];
long long dp[N][11];
long long mx[N];

void check_recursion_invariant(long long depth, long long branches) {
    if (depth > 100 || branches > 9) {  // These are illustrative thresholds
        cerr << "Warning: Recursion invariant triggered - excessive depth or branching!" << endl;
        abort();
    }
}

void check_memoization_invariant(long long n, long long mn) {
    if (n > 2 * mn) {  // Threshold chosen to illustrate inefficient memoization use
        cerr << "Warning: Memoization invariant triggered - inefficient use of memoization!" << endl;
        abort();
    }
}

void check_paint_invariant(long long n, long long mn, const vector<long long>& t) {
    long long count_min = count(t.begin(), t.end(), mn);
    if (n <= mn * count_min) {  // Illustrative threshold
        cerr << "Warning: Paint invariant triggered - close to minimum paint requirement!" << endl;
        abort();
    }
}

long long solve(long long n, long long depth) {
    if (n == 0) return 0;
    if (n < 0) return -int(1e9);
  
    check_recursion_invariant(depth, 9);  // Check recursion depth and branching
    
    if (mx[n] == -1) {
        for (int i = 1; i < 10; i++) {
            dp[n][i] = max(dp[n][i], 1 + solve(n - t[i], depth + 1));
            mx[n] = max(mx[n], dp[n][i]);
        }
    }
    return mx[n];
}

int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    memset(dp, -1, sizeof(dp));
    memset(mx, -1, sizeof(mx));
    
    long long n;
    cin >> n;
    long long mn = int(1e9);
    vector<long long> t_list(10);
    
    for (int i = 1; i < 10; i++) {
        cin >> t[i];
        t_list[i] = t[i];
        mn = min(mn, t[i]);
    }

    check_memoization_invariant(n, mn);  // Check memoization condition
    check_paint_invariant(n, mn, t_list);  // Check paint invariant
    
    if (n < mn) {
        cout << -1;
        return 0;
    }
    
    solve(n, 0);
    long long i = n;
    while (i) {
        int ind = -1;
        for (int j = 1; j <= 9; j++)
            if (dp[i][j] == mx[i] && mx[i] > -1) ind = j;
        if (ind == -1) return 0;
        cout << ind;
        i = i - t[ind];
    }
}