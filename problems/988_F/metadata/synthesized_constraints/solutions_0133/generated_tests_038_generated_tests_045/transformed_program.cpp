#include <bits/stdc++.h>
using namespace std;

int dp[2002][2002];
int arr[2002];
int umbrella[2002];

void check_nested_loop_invariant(int a, int m) {
    if (a > 1500 && m > 1000) { 
        cerr << "Warning: Performance bottleneck due to large 'a' and excessive umbrellas in nested loops!" << endl;
        abort();
    }
}

void check_conditions_in_loop(int n, int m) {
    if (n > m) { 
        cerr << "Warning: Performance bottleneck due to complex umbrella checks relative to rain segments!" << endl;
        abort();
    }
}

void check_dp_table_invariant(int a) {
    if (a > 1500) { 
        cerr << "Warning: Performance bottleneck due to large DP table updates!" << endl;
        abort();
    }
}

int main() {
    for (int i = 0; i <= 2001; i++)
        for (int j = 0; j <= 2001; j++) dp[i][j] = (int)1e9;
    memset(arr, 0, sizeof(arr));
    memset(umbrella, -1, sizeof(umbrella));

    int a, m, n;
    scanf("%d %d %d", &a, &n, &m);

    // Insert performance checkers after reading input
    check_nested_loop_invariant(a, m);
    check_conditions_in_loop(n, m);
    check_dp_table_invariant(a);

    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        for (int j = l; j < r; j++) arr[j] = 1;
    }
    
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (umbrella[x] == -1)
            umbrella[x] = y;
        else
            umbrella[x] = min(umbrella[x], y);
    }
    
    for (int i = 0; i <= 2001; i++) dp[i][a] = 0;
    for (int i = a - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (umbrella[j] == -1) continue;
            dp[j][i] = umbrella[j] + dp[j][i + 1];
            if (umbrella[i] != -1) {
                dp[j][i] = min(dp[j][i], umbrella[i] + dp[i][i + 1]);
            }
            if (!arr[i]) {
                dp[j][i] = min(dp[j][i], dp[2001][i + 1]);
            }
        }
        if (umbrella[i] != -1) {
            dp[2001][i] = umbrella[i] + dp[i][i + 1];
        }
        if (!arr[i]) {
            dp[2001][i] = min(dp[2001][i], dp[2001][i + 1]);
        }
    }
    
    if (dp[2001][0] == (int)1e9)
        printf("-1\n");
    else
        printf("%d\n", dp[2001][0]);
    
    return 0;
}