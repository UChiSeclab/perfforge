#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_dp_initialization_invariant(int n) {
    if (n > 80) {
        cerr << "Warning: DP initialization invariant triggered - potential high initialization cost!" << endl;
        abort();
    }
}

void check_dp_transition_invariant(int zeroCount, int n) {
    if (zeroCount > n / 2) {
        cerr << "Warning: DP state transition invariant triggered - too many missing bulbs!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int n, int filledCount) {
    if (n > 90 && filledCount < 10) {
        cerr << "Warning: Nested loop invariant triggered - high n with sparse filled bulbs!" << endl;
        abort();
    }
}

// Main program
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> p(n + 1);
    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);
    int zeroCount = 0, filledCount = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] == 0)
            zeroCount++;
        else
            filledCount++;
        st.erase(p[i]);
    }

    // Perform checks
    check_dp_initialization_invariant(n);
    check_dp_transition_invariant(zeroCount, n);
    check_nested_loop_invariant(n, filledCount);

    const int MAXN = 105;
    int dp[MAXN][MAXN][MAXN][2];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++) 
                dp[i][j][k][0] = dp[i][j][k][1] = 1000000007;

    int even = 0, odd = 0;
    for (auto x : st) {
        if (x % 2 == 0)
            even++;
        else
            odd++;
    }

    dp[0][even][odd][0] = 0;
    dp[0][even][odd][1] = 0;

    for (int i = 1; i <= n; i++) {
        if (p[i] != 0) {
            int now = p[i] % 2;
            for (int ev = 0; ev <= n; ev++) {
                for (int od = 0; od <= n; od++) {
                    for (int j = 0; j <= 1; j++) {
                        dp[i][ev][od][now] = min(dp[i][ev][od][now],
                                                 dp[i - 1][ev][od][j] + (j == now ? 0 : 1));
                    }
                }
            }
        } else {
            for (int ev = 0; ev <= n; ev++) {
                for (int od = 0; od <= n; od++) {
                    if (ev > 0) {
                        dp[i][ev - 1][od][0] = min(dp[i][ev - 1][od][0], dp[i - 1][ev][od][0]);
                        dp[i][ev - 1][od][0] = min(dp[i][ev - 1][od][0], dp[i - 1][ev][od][1] + 1);
                    }
                    if (od > 0) {
                        dp[i][ev][od - 1][1] = min(dp[i][ev][od - 1][1], dp[i - 1][ev][od][0] + 1);
                        dp[i][ev][od - 1][1] = min(dp[i][ev][od - 1][1], dp[i - 1][ev][od][1]);
                    }
                }
            }
        }
    }

    cout << min(dp[n][0][0][0], dp[n][0][0][1]) << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}