#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int power(int a, int b) {
    int res = 1;
    int call_count = 0; // Track the number of times power is called
    while (b) {
        if (b % 2 != 0) {
            res = (1LL * res * a) % mod;
        }
        a = (1LL * a * a) % mod;
        b /= 2;
        call_count++;
    }
    // Check the invariant for excessive power calls
    check_power_function_invariant(call_count, b);
    return res;
}

void check_large_n_k_invariant(int n, int k) {
    if (n > 5000 && k > 4000) {
        cerr << "Warning: Performance bottleneck condition triggered - large n and k!" << endl;
        abort();
    }
}

void check_power_function_invariant(int calls, int k) {
    if (calls > 10000 && k > 4000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive power function calls!" << endl;
        abort();
    }
}

int ans[5005][5005];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    // Check the invariant for large n and k
    check_large_n_k_invariant(n, k);
    
    if (n <= 5000) {
        int answer = 0;
        for (int i = 0; i <= n; i++) {
            ans[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                ans[i][j] = (ans[i - 1][j - 1] + ans[i - 1][j]) % mod;
            }
        }
        for (int i = 1; i <= n; i++) {
            answer = (answer + (1LL * ans[n][i] * power(i, k)) % mod) % mod;
        }
        printf("%d\n", answer);
    } else {
        int prev = 1;
        for (int i = 1; i <= k; i++) {
            for (int d = 0; d <= k; d++) {
                if (i == 1) {
                    prev = (1LL * prev * (n - d)) % mod;
                    ans[1][d] = (1LL * prev * power(2, n - d - 1)) % mod;
                } else {
                    ans[i][d] =
                        ((1LL * (d + 1) * ans[i - 1][d]) % mod + ans[i - 1][d + 1]) % mod;
                }
            }
        }
        printf("%d\n", ans[k][0]);
    }
    return 0;
}