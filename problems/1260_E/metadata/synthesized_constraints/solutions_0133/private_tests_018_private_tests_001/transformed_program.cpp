#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, M = (1 << 30) - 1, mod = 998244353;

void check_recursion_invariant(int idx, int maxDepth) {
    if (idx > maxDepth) {
        cerr << "Warning: Recursion depth invariant triggered - excessive depth in recursion" << endl;
        abort();
    }
}

void check_dp_invariant(int m, int threshold) {
    if (m > threshold) {
        cerr << "Warning: DP invariant triggered - excessive number of subproblems" << endl;
        abort();
    }
}

void check_subproblem_invariant(int subproblemCount, int threshold) {
    if (subproblemCount > threshold) {
        cerr << "Warning: Subproblem invariant triggered - too many subproblems" << endl;
        abort();
    }
}

void check_input_invariant(const vector<int>& costs, int threshold) {
    int bribableCount = 0;
    for (int cost : costs) {
        if (cost != -1) {
            bribableCount++;
        }
    }
    if (bribableCount > threshold) {
        cerr << "Warning: Input pattern invariant triggered - excessive bribable opponents" << endl;
        abort();
    }
}

long long z[20], dp[int(1 << 18) + 5][20], m;
vector<int> s;

long long solve(int idx, int p) {
    check_recursion_invariant(idx, 131072); // Max depth or index check
    if (idx >= m) return 0;
    long long &ret = dp[idx][p];
    if (~ret) return ret;
    ret = 1e18;
    if (idx < z[p]) ret = min(ret, solve(idx + 1, p));
    ret = min(ret, solve(idx + 1, p + 1) + s[idx]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(0));
    s.clear();
    memset(dp, -1, sizeof dp);
    int n = 8;
    cin >> n;

    check_dp_invariant(n, 262144); // Check number of subproblems based on max n

    vector<pair<int, int> > v, vv;
    bool bo = 0;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        vv.push_back({x, i});
        a.push_back(x);
        if (bo) v.push_back({x, i}), s.push_back(x);
        if (x == -1) bo = 1;
    }

    check_input_invariant(a, 100000); // Arbitrary threshold for bribable opponents

    reverse(s.begin(), s.end());
    m = s.size();
    z[0] = 0;
    for (int i = 1; i < 20; i++) z[i] = n / (1 << i), z[i] += z[i - 1];
    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());
    int cur, c = n / 2;
    long long ans = 0;
    ans = solve(0, 0);
    cout << ans;
    return 0;
}