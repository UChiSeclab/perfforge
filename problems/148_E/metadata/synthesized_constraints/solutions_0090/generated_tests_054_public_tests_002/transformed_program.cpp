#include <bits/stdc++.h>
using namespace std;

void check_dp_complexity_invariant(long long n, long long m, long long totalItems) {
    if (m > totalItems / 2 && n < 10) { // Assuming large m with few shelves
        cerr << "Warning: Performance bottleneck condition - high DP complexity!" << endl;
        abort();
    }
}

void check_sparse_valuable_items(long long n, vector<long long>& shelfValues, long long averageValue) {
    long long highValueCount = 0;
    for (long long value : shelfValues) {
        if (value > averageValue) {
            highValueCount++;
        }
    }
    if (highValueCount < n / 2) { // Assuming less than half shelves have high-value items
        cerr << "Warning: Performance bottleneck condition - sparse valuable items!" << endl;
        abort();
    }
}

void check_combinatorial_space_invariant(long long n, long long m) {
    if (n * m > 5000) { // Threshold for large combinatorial space
        cerr << "Warning: Performance bottleneck condition - large combinatorial space!" << endl;
        abort();
    }
}

const long long MAXN = 1e2 + 10, MXN = 1e4 + 10;
long long n, m, szz, prs[MAXN], mx[MAXN][MAXN], dp[2][MXN];

int32_t main() {
    cin >> n >> m;
    vector<long long> shelfValues;
    long long totalItems = 0;
    for (long long i = 0; i < n; i++) {
        cin >> szz;
        totalItems += szz;
        long long sumShelf = 0;
        for (long long j = 1; j <= szz; j++) {
            cin >> prs[j];
            sumShelf += prs[j];
            prs[j] += prs[j - 1];
        }
        shelfValues.push_back(sumShelf);
        for (long long j = 0; j <= szz; j++)
            for (long long k = j; k <= szz; k++)
                mx[i][j + szz - k] =
                    max(mx[i][j + szz - k], prs[j] + prs[szz] - prs[k]);
    }
    
    // Calculate average value for sparse valuable items check
    long long averageValue = accumulate(shelfValues.begin(), shelfValues.end(), 0LL) / n;

    // Insert checks after input and initial setup
    check_dp_complexity_invariant(n, m, totalItems);
    check_sparse_valuable_items(n, shelfValues, averageValue);
    check_combinatorial_space_invariant(n, m);

    for (long long i = 0; i < MAXN; i++) dp[0][i] = mx[0][i];
    for (long long i = 1; i < n; i++) {
        for (long long j = 1; j < MAXN; j++) {
            if (!mx[i][j]) continue;
            for (long long k = 0; k <= MXN - 10; k++) {
                if (!dp[0][k] and k) continue;
                dp[1][j + k] =
                    max(dp[1][j + k], max(dp[0][j + k], mx[i][j] + dp[0][k]));
            }
        }
        for (long long j = 0; j <= MXN - 10; j++)
            dp[0][j] = max(dp[0][j], dp[1][j]);
    }
    return cout << dp[0][m] << '\n', 0;
}