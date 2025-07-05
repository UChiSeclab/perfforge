#include <bits/stdc++.h>
using namespace std;
const int N = 102;
const long long INF = 1e12;
int n;
string s;
int a[N];
long long ans[N][N];
long long dp[2][N][N][N];

// Check functions
void check_recursion_depth_and_branching(int recursionDepth, int branchingFactor) {
    if (recursionDepth > 50 && branchingFactor > 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth or branching factor!" << endl;
        abort();
    }
}

void check_repeated_function_calls(int calcAnsCalls) {
    if (calcAnsCalls > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive calls to calcAns!" << endl;
        abort();
    }
}

void check_high_cost_in_loops(int loopIterations, int segmentScore) {
    if (loopIterations > 1000 && segmentScore > 100000000) {
        cerr << "Warning: Performance bottleneck condition triggered - high cost in loops!" << endl;
        abort();
    }
}

// Counter for calcAns calls
int calcAnsCallCounter = 0;

long long calcDp(int c, int l, int r, int cnt);

long long calcAns(int l, int r) {
    if (l >= r) return 0;
    long long &res = ans[l][r];
    if (res != -1) return res;
    res = 0;
    
    calcAnsCallCounter++;
    check_repeated_function_calls(calcAnsCallCounter); // Check for excessive calcAns calls

    for (int cnt = 1; cnt <= r - l; ++cnt) {
        int loopIterations = r - l;
        int segmentScore = a[cnt - 1];
        check_high_cost_in_loops(loopIterations, segmentScore); // Check for high cost in loops

        res = max(res, calcDp(0, l, r, cnt) + a[cnt - 1]);
        res = max(res, calcDp(1, l, r, cnt) + a[cnt - 1]);
    }
    return res;
}

long long calcDp(int c, int l, int r, int cnt) {
    if (cnt == 0) return calcAns(l, r);
    long long &res = dp[c][l][r][cnt];
    if (res != -1) return res;
    res = -INF;
    
    int recursionDepth = r - l;
    int branchingFactor = r - l;
    check_recursion_depth_and_branching(recursionDepth, branchingFactor); // Check for recursion depth and branching

    for (int i = l; i < r; ++i) {
        if (c == s[i] - '0')
            res = max(res, calcAns(l, i) + calcDp(c, i + 1, r, cnt - 1));
    }
    return res;
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) cin >> a[i];
    memset(dp, -1, sizeof dp);
    memset(ans, -1, sizeof ans);
    cout << calcAns(0, n) << endl;
    return 0;
}