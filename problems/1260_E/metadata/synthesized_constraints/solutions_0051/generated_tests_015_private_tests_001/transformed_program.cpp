#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int dx8[] = {-1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[] = {0, -1, 0, 1, 1, -1, 1, -1};

long long min(long long a, long long b) {
    if (a < b) return a;
    return b;
}
long long max(long long a, long long b) {
    if (a > b) return a;
    return b;
}
long long ceil1(long long a, long long b) { return (a + b - 1) / b; }

void read(vector<long long>& arr) {
    for (long long i = 0; i < int(arr.size()); i++) cin >> arr[i];
}

void read_graph(vector<vector<long long>>& g, long long m) {
    while (m--) {
        long long x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

long long n;
long long inf = numeric_limits<long long>::max();
long long lim = 30;
vector<vector<long long>> dp;
vector<long long> cnt, arr;

long long calc(long long pos, long long fuel, long long c, long long& recursiveCalls, long long& memoHits) {
    recursiveCalls++;
    if (pos == n) return 0;
    long long res = inf;
    if (arr[pos] == -1) return 0;
    if (c == lim) return 0;
    if (dp[pos][c] != -1) {
        memoHits++;
        return dp[pos][c];
    }
    if (fuel == 0) {
        res = min(res, calc(pos + 1, fuel + cnt[c + 1], c + 1, recursiveCalls, memoHits) + arr[pos]);
    } else {
        res = min(res, calc(pos + 1, fuel - 1, c, recursiveCalls, memoHits));
        res = min(res, calc(pos + 1, fuel + cnt[c + 1], c + 1, recursiveCalls, memoHits) + arr[pos]);
    }
    dp[pos][c] = res;
    return res;
}

void solve() {
    cin >> n;
    lim = min(lim, n);
    arr = vector<long long>(n);
    read(arr);
    cnt = vector<long long>(lim + 3, 0);
    long long pw = n / 2;
    for (long long i = 1; i <= lim; i++) {
        cnt[i] = pw - 1;
        pw /= 2;
    }
    reverse(arr.begin(), arr.end());
    dp = vector<vector<long long>>(n + 3, vector<long long>(lim, -1));

    long long recursiveCalls = 0;
    long long memoHits = 0;

    // Run calculation and check performance characteristics
    long long result = calc(0, 0, 0, recursiveCalls, memoHits);
    check_recursive_calls(recursiveCalls, n);
    check_memoization_usage(memoHits, recursiveCalls);

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}