#include <bits/stdc++.h>
using namespace std;

int digit_to_int[] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010,
                      0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
short dp[2010][2010][10];
short segnum[2010][2010][10];
short pre[2010][2010][10];
int scoreboard[2010];

// Checker functions
void check_combination_invariant(int n, int k) {
    if (n > 1000 && k > 500) { // Large n and k can cause slowdown
        cerr << "Warning: combination_invariant triggered - complex combinations of digits" << endl;
        abort();
    }
}

void check_active_segments_invariant(int n, int k, const vector<int>& scoreboard) {
    int inactiveSegments = 0;
    for (int score : scoreboard) {
        inactiveSegments += 7 - __builtin_popcount(score);
    }
    if (k > inactiveSegments * 0.8) { // If k is more than 80% of inactive segments
        cerr << "Warning: active_segments_invariant triggered - too many active segments" << endl;
        abort();
    }
}

void check_dp_space_invariant(int n, int k) {
    if (n * k > 1500000) { // Large DP space threshold
        cerr << "Warning: dp_space_invariant triggered - large DP space" << endl;
        abort();
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    
    vector<int> scoreboard_vec(n);
    for (int i = 0; i < n; i++) {
        char t[8];
        scanf("%s", t);
        for (int j = 0; j < 7; j++) {
            scoreboard[i] <<= 1;
            scoreboard[i] |= t[j] - '0';
        }
        scoreboard_vec[i] = scoreboard[i];
    }
    
    // Apply performance checkers after input parsing
    check_combination_invariant(n, k);
    check_active_segments_invariant(n, k, scoreboard_vec);
    check_dp_space_invariant(n, k);

    int cur = 0;
    fill(dp[cur][0], dp[cur][0] + 10, 1);
    for (int i = n - 1; i >= 0; i--) {
        fill(&dp[cur ^ 1][0][0], &dp[cur ^ 1][0][0] + 2010 * 10, (short)0);
        for (int d = 0; d <= 9; d++) {
            if ((scoreboard[i] & digit_to_int[d]) == scoreboard[i]) {
                int diff = __builtin_popcount(digit_to_int[d] - scoreboard[i]);
                for (int j = 0; j <= k; j++) {
                    for (int m = 0; m <= 9; m++) {
                        if (dp[cur][j][m]) {
                            dp[cur ^ 1][j + diff][d] = 1;
                            pre[i][j + diff][d] = m;
                            segnum[i][j + diff][d] = diff;
                        }
                    }
                }
            }
        }
        cur ^= 1;
    }

    int ans = -1;
    for (int i = 9; i >= 0; i--) {
        if (dp[cur][k][i]) {
            ans = i;
            break;
        }
    }
    if (ans == -1) {
        puts("-1");
        return 0;
    }
    printf("%d", ans);
    int seg = k;
    for (int i = 0; i < n - 1; i++) {
        int c = pre[i][seg][ans];
        int s = segnum[i][seg][ans];
        ans = c;
        seg -= s;
        printf("%d", ans);
    }
    return 0;
}