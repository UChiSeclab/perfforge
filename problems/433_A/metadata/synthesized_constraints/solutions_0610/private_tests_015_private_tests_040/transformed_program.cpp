#include <bits/stdc++.h>
using namespace std;

// Checker for high sum condition
void check_high_sum_condition(int sum, int n) {
    if (sum > (n * 200 / 2) * 0.9) {
        cerr << "Warning: Performance bottleneck condition triggered due to high sum!" << endl;
        abort();
    }
}

// Checker for imbalance in weights
void check_imbalance_condition(int count100, int count200, int n) {
    if (count100 < n * 0.1 && count200 > n * 0.9) {
        cerr << "Warning: Performance bottleneck condition triggered due to imbalance in weights!" << endl;
        abort();
    }
}

// Checker for high iteration potential
void check_high_iterations_condition(int sum) {
    if (sum > 9000) {
        cerr << "Warning: Performance bottleneck condition triggered due to high loop iterations!" << endl;
        abort();
    }
}

int main() {
    int n, sum = 0, f[10005] = {0}, a[105];
    int count100 = 0, count200 = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        if (a[i] == 100) count100++;
        else if (a[i] == 200) count200++;
    }

    // Check for high sum condition
    check_high_sum_condition(sum, n);

    // Check for imbalance in weights
    check_imbalance_condition(count100, count200, n);

    // Calculate the target sum for partitioning
    sum /= 2;

    // Check for potential high iterations
    check_high_iterations_condition(sum);

    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= a[i]; j--) {
            f[j] = max(f[j], f[j - a[i]] + a[i]);
        }
    }

    if (f[sum] == sum) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}