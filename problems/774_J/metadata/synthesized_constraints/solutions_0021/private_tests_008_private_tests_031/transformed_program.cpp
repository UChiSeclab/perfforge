#include <bits/stdc++.h>
using namespace std;

int dp[110][110][110];
int n, m;
char a[110];

void check_uncertain_invariant(int numUncertain, int n) {
    if (numUncertain > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - too many uncertain episodes!" << endl;
        abort();
    }
}

void check_consecutive_unknowns_invariant(int maxConsecutiveUncertain, int n) {
    if (maxConsecutiveUncertain > n / 3) {
        cerr << "Warning: Performance bottleneck condition triggered - too many consecutive uncertain episodes!" << endl;
        abort();
    }
}

void check_mixed_invariant(int numUncertain, int numY, int n) {
    if (numUncertain > (n - numY) / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - high mix of uncertain episodes!" << endl;
        abort();
    }
}

int func(int here, int ch, int ch1) {
    if (here == n) {
        if (ch1 == m)
            return 1;
        else
            return 0;
    }
    int &ret = dp[here][ch][ch1];
    if (ret != -1) return ret;
    ret = 0;
    if (a[here] == 'N')
        ret = func(here + 1, ch + 1, max(ch + 1, ch1));
    else if (a[here] == 'Y')
        ret = func(here + 1, 0, ch1);
    else {
        ret = max(func(here + 1, ch + 1, max(ch + 1, ch1)), func(here + 1, 0, ch1));
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf(" %1c", &a[i]);
    
    // Pre-calculate conditions for the invariants
    int numUncertain = 0, maxConsecutiveUncertain = 0, currentConsecutiveUncertain = 0, numY = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '?') {
            numUncertain++;
            currentConsecutiveUncertain++;
        } else {
            maxConsecutiveUncertain = max(maxConsecutiveUncertain, currentConsecutiveUncertain);
            currentConsecutiveUncertain = 0;
        }
        if (a[i] == 'Y') {
            numY++;
        }
    }
    maxConsecutiveUncertain = max(maxConsecutiveUncertain, currentConsecutiveUncertain);

    // Insert performance-checking conditions
    check_uncertain_invariant(numUncertain, n);
    check_consecutive_unknowns_invariant(maxConsecutiveUncertain, n);
    check_mixed_invariant(numUncertain, numY, n);

    if (func(0, 0, 0))
        puts("YES");
    else
        puts("NO");
}