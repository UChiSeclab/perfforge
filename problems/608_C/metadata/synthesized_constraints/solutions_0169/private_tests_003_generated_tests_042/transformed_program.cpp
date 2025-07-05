#include <bits/stdc++.h>
using namespace std;

void check_maxi_invariant(int maxi) {
    if (maxi > 900000) {
        cerr << "Warning: Performance bottleneck condition triggered - high maximum position value!" << endl;
        abort();
    }
}

void check_power_invariant(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 900000) {
            cerr << "Warning: Performance bottleneck condition triggered - wide range of destructive power!" << endl;
            abort();
        }
    }
}

void check_array_operations_invariant(int maxi) {
    if (maxi > 900000) {
        cerr << "Warning: Performance bottleneck condition triggered - large range of operations on auxiliary arrays!" << endl;
        abort();
    }
}

int main() {
    int n, arr[1000069] = {}, dp[1000069] = {}, f[1000069] = {};
    cin >> n;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
        arr[x] = y;
        f[x] = 1;
        maxi = max(maxi, x);
    }

    // Check for performance bottlenecks after input is read
    check_maxi_invariant(maxi);
    check_power_invariant(arr, maxi + 1);
    check_array_operations_invariant(maxi);

    for (int i = 1; i < maxi + 1; i++) f[i] = f[i - 1] + f[i];
    for (int i = 1; i < maxi + 1; i++) {
        if (i - arr[i] - 1 >= 0) {
            dp[i] = dp[i - arr[i] - 1] + (f[i - 1] - f[i - arr[i] - 1]);
        } else {
            dp[i] = f[i - 1];
        }
    }
    int ans = maxi + 2;
    for (int i = 0; i < maxi + 1; i++) {
        ans = min(ans, dp[i] + (f[maxi] - f[i]));
    }
    cout << ans;

    return 0;
}