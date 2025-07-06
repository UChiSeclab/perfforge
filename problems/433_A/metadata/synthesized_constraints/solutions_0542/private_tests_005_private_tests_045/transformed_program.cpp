#include <bits/stdc++.h>
using namespace std;
const int MAX = 205;
int a[MAX];
bool dp[MAX];

// Checker functions (as defined in Phase 3)
void check_apple_count_and_distribution(int n, int num_200g);
void check_weight_distribution(int sum, int num_200g);
void check_dp_saturation(bool *dp, int sum);

int main() {
    int n;
    scanf("%d", &n);
    int num_200g = 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] == 200) {
            num_200g++;
        }
        a[i] /= 100;
        sum += a[i];
    }

    // Add checkers after reading inputs
    check_apple_count_and_distribution(n, num_200g);
    check_weight_distribution(sum, num_200g);

    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 200; j >= 1; --j) {
            if (dp[j - a[i]]) dp[j] = 1;
        }
    }

    // Check for DP saturation just before the final decision
    check_dp_saturation(dp, sum);

    if (sum % 2 || !dp[sum / 2])
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}