#include <bits/stdc++.h>
using namespace std;
const int N = 2005, inf = 1e9;
int mark[N], val[N];
int a, n, m;
int dp[2][N][N];

void check_recursion_invariant(int recursionDepth, int maxAllowedDepth) {
    if (recursionDepth > maxAllowedDepth) {
        cerr << "Warning: Recursion depth invariant triggered - excessive recursion depth" << endl;
        abort();
    }
}

void check_rain_segment_invariant(int rainSegmentCount, int maxAllowedSegments) {
    if (rainSegmentCount > maxAllowedSegments) {
        cerr << "Warning: Rain segment invariant triggered - too many rain segments" << endl;
        abort();
    }
}

void check_umbrella_weight_invariant(int umbrellaWeight, int maxAllowedWeight) {
    if (umbrellaWeight > maxAllowedWeight) {
        cerr << "Warning: Umbrella weight invariant triggered - excessive umbrella weight" << endl;
        abort();
    }
}

int fun(int pos, int ind, bool present, int depth) {
    check_recursion_invariant(depth, 100); // Check for excessive recursion depth
    if (pos == a + 1) return 0;
    if (dp[present][pos][ind] != -1) return dp[present][pos][ind];
    int ans = inf;
    int newind = ((val[pos] < val[ind]) ? pos : ind);
    if ((present && mark[pos] == -1) || (!present && !mark[pos]))
        ans = min(fun(pos + 1, a + 1, false, depth + 1),
                  val[newind] + fun(pos + 1, newind, false, depth + 1));
    else if (present || mark[pos] == 1)
        ans = val[newind] + fun(pos + 1, newind, true, depth + 1);
    ans = min(ans, inf);
    return dp[present][pos][ind] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> a >> n >> m;

    // Check for excessive rain segments
    check_rain_segment_invariant(n, a / 2);

    for (int i = 1; i < n + 1; i++) {
        int x, y;
        cin >> x >> y;
        mark[x] = 1;
        mark[y] = -1;
    }
    for (int i = 0; i < a + 2; i++) val[i] = inf;
    for (int i = 1; i < m + 1; i++) {
        int x, y;
        cin >> x >> y;
        // Check for excessive umbrella weight
        check_umbrella_weight_invariant(y, 100000);
        val[x] = min(val[x], y);
    }
    int ans = fun(0, a + 1, 0, 0);
    if (ans >= inf) ans = -1;
    cout << ans << endl;
    return 0;
}