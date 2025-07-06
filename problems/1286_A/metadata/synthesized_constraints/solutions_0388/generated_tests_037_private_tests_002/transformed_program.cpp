#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_zero_count(int zeroCount, int n) {
    if (zeroCount > n * 0.9) { // Threshold: more than 90% are zeros
        cerr << "Warning: Performance bottleneck condition triggered - high number of zeros in input!" << endl;
        abort();
    }
}

void check_max_input_size(int n) {
    if (n == 100) {
        cerr << "Warning: Performance bottleneck condition triggered - maximum input size reached!" << endl;
        abort();
    }
}

void check_large_dp_iterations(int n) {
    if (n * n > 10000) { // Threshold: number of iterations in DP exceeds 10,000
        cerr << "Warning: Performance bottleneck condition triggered - large DP array operations!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    // Check maximum input size
    check_max_input_size(n);
    
    int a[n+1]; // Adjusted size for 1-based indexing
    int zeroCount = 0;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 0) zeroCount++;
    }
    
    // Check high count of zeros
    check_high_zero_count(zeroCount, n);
    
    // 4-dimensional DP array defined
    const int inf = 1e9 + 10;
    int f[n+1][3][n+1][n+1], ans;
    
    // Initialize DP array
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j) {
            f[0][0][i][j] = inf;
            f[0][1][i][j] = inf;
        }
    f[0][0][0][0] = f[0][1][0][0] = 0;
    
    // Nested loop operations in the DP solution
    // Check large DP array iterations
    check_large_dp_iterations(n);
    
    for (int i = 1; i <= n; ++i)
        for (int chan = 0; chan <= n; ++chan)
            for (int le = 0; le <= n; ++le) {
                for (int j = 0; j < 2; ++j) f[i][j][chan][le] = inf;
                if (a[i]) {
                    if (a[i] % 2) {
                        if (le)
                            for (int j = 0; j < 2; ++j)
                                f[i][1][chan][le] = min(f[i][1][chan][le],
                                                        f[i - 1][j][chan][le - 1] + (j != 1));
                    } else {
                        if (chan)
                            for (int j = 0; j < 2; ++j)
                                f[i][0][chan][le] = min(f[i][0][chan][le],
                                                        f[i - 1][j][chan - 1][le] + (j != 0));
                    }
                } else {
                    if (le)
                        for (int j = 0; j < 2; ++j)
                            f[i][1][chan][le] =
                                min(f[i][1][chan][le], f[i - 1][j][chan][le - 1] + (j != 1));
                    if (chan)
                        for (int j = 0; j < 2; ++j)
                            f[i][0][chan][le] =
                                min(f[i][0][chan][le], f[i - 1][j][chan - 1][le] + (j != 0));
                }
            }
    
    // Calculate final answer
    ans = inf;
    for (int j = 0; j < 2; ++j) ans = min(ans, f[n][j][n / 2][n - n / 2]);
    
    cout << ans;
    return 0;
}