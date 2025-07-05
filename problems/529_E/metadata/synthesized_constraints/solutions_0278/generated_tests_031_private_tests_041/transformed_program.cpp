#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1000 * 1000 * 100 + 1;
const int INF = 99999999;
int k, n;
vector<int> coins;
bitset<maxn> mark;

void check_large_withdrawal_single_denom(int an, int lowest_denom) {
    if (an > 1000000 && lowest_denom <= 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to large withdrawal amount with low denomination!" << endl;
        abort();
    }
}

void check_high_multiplicative_checks(int an, int smallest_denom, int k) {
    if (an > 1000000 && smallest_denom * k <= an) {
        cerr << "Warning: Performance bottleneck condition triggered due to high multiplicative checks!" << endl;
        abort();
    }
}

void check_extensive_factor_checking(int An, int k) {
    if (An > 1000000 && k > 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to extensive factor checking!" << endl;
        abort();
    }
}

int main() {
    int an;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> an;
        coins.push_back(an);
        mark[an] = true;
    }
    sort(coins.begin(), coins.end());

    int q;
    cin >> q;
    while (q-- > 0) {
        cin >> an;

        // Check for potential performance bottlenecks
        check_large_withdrawal_single_denom(an, coins[0]);

        int res = INF;
        for (int a = 0; a < coins.size() and coins[a] <= an; a++) {
            for (int t = 1; t <= k and t * coins[a] <= an; t++) {
                int An = an - coins[a] * t;

                // Check for potential performance bottlenecks
                check_high_multiplicative_checks(an, coins[a], k);
                check_extensive_factor_checking(An, k);

                int Dp = INF;
                vector<int> M(0);
                for (int i = 1; i * i <= An and i <= k; i++)
                    if (An % i == 0) M.push_back(i), M.push_back(An / i);
                for (int i = 0; i < M.size(); i++)
                    if (mark[M[i]]) Dp = min(Dp, An / M[i]);
                if (An == 0) Dp = 0;
                if (An >= 0 and Dp != INF) res = min(res, t + Dp);
            }
        }
        if (res > k) res = -1;
        cout << res << endl;
    }
    return 0;
}