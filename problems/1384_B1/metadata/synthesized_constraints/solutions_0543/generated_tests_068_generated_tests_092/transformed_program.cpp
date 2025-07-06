#include <bits/stdc++.h>
using namespace std;

int inf = 0x3f3f3f3f;
const int N = 2e5 + 7;
int n, k, l, h;
int dp[107][N], a[N];

// Checkers for performance bottlenecks
void check_tide_limit_interaction(int a[], int n, int k, int l) {
    for (int i = 1; i <= n; i++) {
        if (a[i] + k <= l) {
            cerr << "Warning: Performance bottleneck condition triggered - High Tide-Limit Interaction!" << endl;
            abort();
        }
    }
}

void check_iteration_count(int n, int k) {
    if (k >= 100) {
        cerr << "Warning: Performance bottleneck condition triggered - High Iteration Count!" << endl;
        abort();
    }
}

void check_depth_tide_synchrony(int a[], int n, int k, int l) {
    int max_tide = k;
    for (int i = 1; i <= n; i++) {
        int average_depth = (a[i] + max_tide) / 2;
        if (average_depth <= l) {
            cerr << "Warning: Performance bottleneck condition triggered - Depth Distribution and Tide Synchrony!" << endl;
            abort();
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%d%d%d", &n, &k, &l);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        
        // Integrate performance checkers
        check_tide_limit_interaction(a, n, k, l);
        check_iteration_count(n, k);
        check_depth_tide_synchrony(a, n, k, l);

        for (int i = 0; i <= 2 * k * n; i++) dp[0][i] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 2 * k * n; j++) {
                if (dp[i - 1][j - 1] == -1 && dp[i][j - 1] == -1) continue;
                if (j % (2 * k) < k)
                    h = a[i] + j % k;
                else
                    h = a[i] + k - (j % k);
                if (h <= l) dp[i][j] = 0;
            }
        }
        int fl = 0;
        for (int i = 0; i <= 10000; i++) {
            if (dp[n][i] == 0) fl = 1;
        }
        if (fl == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}