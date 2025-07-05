#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 100;
int dist[2006][15], ans[2005];
vector<int> v[2005];
int dp[2006][2005], pre[2005][2006], num[2005][2005];
char arr[2005][15];
char str[15][15] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                    "1101011", "1101111", "1010010", "1111111", "1111011"};

void check_large_n_k_invariant(int n, int k) {
    if (n >= 1800 && k >= 1800) {
        cerr << "Warning: Large n and k values - potential performance bottleneck!" << endl;
        abort();
    }
}

void check_calc_frequency_invariant(int callCount, int threshold) {
    if (callCount > threshold) {
        cerr << "Warning: calc function called too many times - potential performance bottleneck!" << endl;
        abort();
    }
}

void check_digit_transformation_invariant(int operations) {
    if (operations > 10) {
        cerr << "Warning: Excessive digit transformations in calc function!" << endl;
        abort();
    }
}

void check_dp_state_invariant(int dpSize, int threshold) {
    if (dpSize > threshold) {
        cerr << "Warning: Dynamic programming state space too large!" << endl;
        abort();
    }
}

int calc(char a[], char b[]) {
    int ret = 0;
    int operations = 0;  // Track operations for invariant check
    for (int i = 0; i < 7; i++) {
        if (a[i] == '0' && b[i] == '1')
            ret++;
        else if (a[i] == b[i])
            ;
        else {
            ret = 0x3f3f3f3f;
            break;
        }
        operations++;  // Count operations
    }
    check_digit_transformation_invariant(operations);  // Check after transformation
    return ret;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    
    check_large_n_k_invariant(n, k);  // Check after input

    for (int i = 0; i < n; i++) scanf("%s", arr[i]);
    for (int i = 0; i < n; i++) {
        int now = 0x3f3f3f3f;
        for (int j = 0; j <= 9; j++) {
            dist[i][j] = calc(arr[i], str[j]);
        }
    }
    
    int calcCallCount = n * 10;  // Number of times calc is called
    check_calc_frequency_invariant(calcCallCount, 5000);  // Example threshold

    memset(pre, -1, sizeof(pre));
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 2000; j >= 0; j--) {
            for (int k = 0; k <= 9; k++) {
                if (j - dist[i][k] >= 0 && dp[i + 1][j - dist[i][k]]) {
                    dp[i][j] = 1, pre[i][j] = j - dist[i][k], num[i][j] = k;
                }
            }
        }
    }
    
    check_dp_state_invariant(n * 2000, 1000000);  // Example threshold

    if (dp[0][k]) {
        int tot = 0;
        int nowa = 0, nowb = k;
        while (nowa < n) {
            ans[++tot] = num[nowa][nowb];
            nowb = pre[nowa][nowb];
            nowa++;
        }
        for (int i = 1; i <= tot; i++) printf("%d", ans[i]);
        printf("\n");
    } else
        printf("-1\n");
    return 0;
}