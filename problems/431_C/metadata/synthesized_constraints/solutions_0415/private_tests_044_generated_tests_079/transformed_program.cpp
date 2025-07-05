#include <bits/stdc++.h>
using namespace std;
int n, k, d;
long long arr[101][101][2];

void check_recursion_invariant(int k) {
    if (k > 80) {
        cerr << "Warning: Performance bottleneck condition triggered - high branching factor due to large k!" << endl;
        abort();
    }
}

void check_caching_invariant(int n) {
    if (n > 80) {
        cerr << "Warning: Performance bottleneck condition triggered - high n leading to potential caching issues!" << endl;
        abort();
    }
}

void check_path_weight_invariant(int n, int d) {
    if (n > 80 && d < n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - potential high recursion due to path weights!" << endl;
        abort();
    }
}

long long dp(long long sum, int num, int Bool) {
    if (sum > n) return 0;
    long long &ret = arr[sum][num][Bool];
    if (ret != -1) return ret;
    if (num >= d) Bool = 1;
    if (sum == n && Bool == 0)
        return 0;
    else if (sum == n && Bool == 1)
        return 1;
    long long temp = 0;
    for (int i = 1; i <= k; i++) {
        temp = ((dp(sum + i, i, Bool) % 1000000007) + temp) % 1000000007;
    }
    return ret = temp;
}

int main() {
    cin >> n >> k >> d;

    // Performance checkers
    check_recursion_invariant(k);
    check_caching_invariant(n);
    check_path_weight_invariant(n, d);

    // Initialize memoization table
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            for (int k = 0; k < 2; k++) {
                arr[i][j][k] = -1;
            }
        }
    }

    cout << dp(0, 1, 0) << endl;
    return 0;
}