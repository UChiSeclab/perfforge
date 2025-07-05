#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

// Checkers for performance invariants
void check_dp_state_explosion(int n, int zero_count) {
    if (zero_count > n / 2) {
        cerr << "Warning: DP state explosion triggered - too many unset bulbs!" << endl;
        abort();
    }
}

void check_nested_loop_complexity(int n, int zero_count) {
    if (n == 100 && zero_count > n / 2) {
        cerr << "Warning: Nested loop complexity triggered - high n with many unset bulbs!" << endl;
        abort();
    }
}

void check_condition_evaluation_overhead(int consecutive_zeros) {
    if (consecutive_zeros > 20) {
        cerr << "Warning: Condition evaluation overhead triggered - too many consecutive unset bulbs!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(2);
    int zero_count = 0;
    int consecutive_zeros = 0;
    for (int& x : a) {
        cin >> x;
        if (x == 0) {
            zero_count++;
            consecutive_zeros++;
        } else {
            consecutive_zeros = 0;
        }
    }
    
    // Place checks after input processing
    check_dp_state_explosion(n, zero_count);
    check_nested_loop_complexity(n, zero_count);
    check_condition_evaluation_overhead(consecutive_zeros);

    cnt[0] = n / 2;
    cnt[1] = (n + 1) / 2;
    int const INF = n + 20;
    vector<vector<vector<vector<int>>>> dp(
        n + 1,
        vector<vector<vector<int>>>(
            cnt[0] + 2, vector<vector<int>>(cnt[1] + 2, vector<int>(2, INF))));
    dp[0][0][0][0] = dp[0][0][0][1] = 0;
    auto relax = [&](int& x, int y) {
        if (y < x) {
            x = y;
            return true;
        }
        return false;
    };
    for (int i = 0; i < n; ++i) {
        for (int x = 0; x <= cnt[0]; ++x) {
            for (int y = 0; y <= cnt[1]; ++y) {
                for (int par : {0, 1}) {
                    for (int new_par : {0, 1}) {
                        if (dp[i][x][y][par] == INF) {
                            continue;
                        }
                        auto new_x = x;
                        auto new_y = y;
                        int add = 0;
                        if (a[i] > 0) {
                            if (new_par != a[i] % 2) {
                                continue;
                            }
                            if (a[i] % 2 == 0) {
                                new_x++;
                                add += par;
                            } else {
                                new_y++;
                                add += !par;
                            }
                        } else {
                            if (!new_par) {
                                new_x++;
                                add += par;
                            } else {
                                new_y++;
                                add += !par;
                            }
                        }
                        relax(dp[i + 1][new_x][new_y][new_par], dp[i][x][y][par] + add);
                    }
                }
            }
        }
    }
    int ans = INF;
    for (int p : {0, 1}) {
        relax(ans, dp.back()[cnt[0]][cnt[1]][p]);
    }
    cout << ans << '\n';
    return 0;
}