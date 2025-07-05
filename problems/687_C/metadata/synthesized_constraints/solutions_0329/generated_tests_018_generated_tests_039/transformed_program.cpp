#include <bits/stdc++.h>
using namespace std;

void check_combinations_invariant(int n, int k, const vector<int>& coins) {
    int sumCoins = accumulate(coins.begin(), coins.end(), 0);
    if (n > 400 && sumCoins > 2 * k) {
        cerr << "Warning: combinations_invariant triggered - too many combinations possible!" << endl;
        abort();
    }
}

void check_nested_loops_invariant(int n, int k, const vector<int>& coins) {
    int max_coin = *max_element(coins.begin(), coins.end());
    if (max_coin < k / 2) { 
        cerr << "Warning: nested_loops_invariant triggered - frequent conditions met!" << endl;
        abort();
    }
}

void check_dp_array_size_invariant(int n, int k) {
    if ((n * (k + 1) * (k + 1)) > 1250000) { 
        cerr << "Warning: dp_array_size_invariant triggered - large DP array size!" << endl;
        abort();
    }
}

void check_input_size_invariant(int n, int sumCoins, int k) {
    if (n > 450 && sumCoins > 2 * k) {
        cerr << "Warning: input_size_invariant triggered - large n and sum of coins!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    
    vector<int> inp(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
    }
    
    // Calculate the sum of all coins
    int sumCoins = accumulate(inp.begin(), inp.end(), 0);

    // Check conditions after reading input
    check_combinations_invariant(n, k, inp);
    check_input_size_invariant(n, sumCoins, k);

    vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(k + 1, vector<bool>(k + 1, 0)));
    
    // Check DP array size invariant
    check_dp_array_size_invariant(n, k);
    
    dp[0][0][0] = 1;
    
    // Check nested loops invariant
    check_nested_loops_invariant(n, k, inp);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= k; l++) {
                dp[i][j][l] =
                    dp[i - 1][j][l] ||
                    (j >= inp[i - 1]
                         ? dp[i - 1][j - inp[i - 1]][l] ||
                               (l >= inp[i - 1]
                                    ? dp[i - 1][j - inp[i - 1]][l - inp[i - 1]]
                                    : 0)
                         : 0);
            }
        }
    }
    
    map<int, int> a;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (dp[i][k][j] == 1) {
                a[j] = 1;
            }
        }
    }
    
    cout << a.size() << endl;
    for (map<int, int>::iterator it = a.begin(); it != a.end(); it++)
        cout << it->first << " ";
    cout << endl;
}