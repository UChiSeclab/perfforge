#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f;
const int MAXN = 5e3 + 5;
const int MOD = 1e9 + 7;
const int MAX_ASCII_CODE = 26;
const int MAX_NUMBER_OF_NODES = 1e5 + 5;
int dp[MAXN];
int temp[MAXN];

void check_proximity_and_trip_size(int a, int b, int k, int n, int threshold_k, int proximity_limit) {
    if (abs(a - b) <= proximity_limit && k > threshold_k) {
        cerr << "Warning: Performance bottleneck condition triggered due to proximity of 'a' and 'b' with large 'k'!" << endl;
        abort();
    }
}

void check_small_difference_and_max_k(int a, int b, int k, int n, int max_k, int small_diff_threshold) {
    if (abs(a - b) <= small_diff_threshold && k == max_k) {
        cerr << "Warning: Performance bottleneck condition triggered due to small difference between 'a' and 'b' with maximum 'k'!" << endl;
        abort();
    }
}

void check_large_floor_range_and_trip_count(int n, int k, int threshold_n, int threshold_k) {
    if (n > threshold_n && k > threshold_k) {
        cerr << "Warning: Performance bottleneck condition triggered due to large floor range with high number of trips!" << endl;
        abort();
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);
    cout << fixed << setprecision(10);
    int n, a, b, k;
    cin >> n >> a >> b >> k;

    // Insert checks right after reading input
    check_proximity_and_trip_size(a, b, k, n, 3000, 10);
    check_small_difference_and_max_k(a, b, k, n, 5000, 5);
    check_large_floor_range_and_trip_count(n, k, 4000, 2000);

    dp[a] = 1;
    int ans = 0;
    int sav;

    if (a > b) {
        for (int i = 0; i < k; i++) {
            for (int j = b + 2; j <= n; j++) {
                if (j + j - b - 1 < n)
                    temp[j + j - b - 1] = (temp[j + j - b - 1] + dp[j]) % MOD;
                else
                    temp[n] = (temp[n] + dp[j]) % MOD;
            }
            for (int j = n; j > b; j--) {
                temp[j] = (temp[j] + temp[j + 1]) % MOD;
                dp[j] = (MOD + temp[j] - dp[j]) % MOD;
            }
            sav = temp[b + 1];
            memset(temp, 0, sizeof(temp));
        }
        for (int j = b + 2; j <= n; j++) {
            ans = (ans + dp[j]) % MOD;
        }
        ans = (ans + sav) % MOD;
        cout << ans << "\n";
    }
    if (b > a) {
        for (int i = 0; i < k; i++) {
            for (int j = b - 2; j > 0; j--) {
                if (j - b + j + 1 > 0)
                    temp[j + j - b + 1] = (temp[j + j - b - 1] + dp[j]) % MOD;
                else
                    temp[1] = (temp[1] + dp[j]) % MOD;
            }
            for (int j = 1; j < b; j++) {
                temp[j] = (temp[j] + temp[j - 1]) % MOD;
                dp[j] = (temp[j] - dp[j] + MOD) % MOD;
            }
            sav = temp[b - 1];
            memset(temp, 0, sizeof(temp));
        }
        for (int j = 1; j < b - 1; j++) {
            ans = (ans + dp[j]) % MOD;
        }
        ans = (ans + sav) % MOD;
        cout << ans << "\n";
    }
}