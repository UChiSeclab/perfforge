#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
const int mxn = 1e6;
int n, cnt[mxn + 5][2];

// Checker functions based on invariants
void check_histogram_depletion(int j, int range) {
    if (j < range) {
        cerr << "Warning: Histogram depletion invariant triggered - excessive decrementing of j due to insufficient pairings!" << endl;
        abort();
    }
}

void check_uneven_distribution(int cnt[][2], int range) {
    int odd_count = 0;
    for (int i = 0; i < range; ++i) {
        if (cnt[i][0] & 1) ++odd_count;
    }
    if (odd_count > range / 2) {
        cerr << "Warning: Uneven distribution invariant triggered - many odd occurrences in stick lengths!" << endl;
        abort();
    }
}

void check_exhaustive_pair_search(int cnt[][2], int range) {
    int insufficient_pairs = 0;
    for (int i = 0; i < range; ++i) {
        if (cnt[i][0] < 2) ++insufficient_pairs;
    }
    if (insufficient_pairs > range / 2) {
        cerr << "Warning: Exhaustive pair search invariant triggered - frequent failures in pairing!" << endl;
        abort();
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        ++cnt[l][0];
    }

    // Insert check for uneven distribution after input processing
    check_uneven_distribution(cnt, mxn + 5);

    for (int i = 1e6; i >= 2; --i) {
        if ((cnt[i][0] & 1) && cnt[i][1] != cnt[i][0]) {
            --cnt[i][0];
            ++cnt[i - 1][0];
            ++cnt[i - 1][1];
        }
    }
    int j = 1e6;
    ll ans = 0;
    for (int i = 1e6; i >= 1; --i) {
        if (cnt[i][0] <= 1) continue;
        ans += cnt[i][0] / 4 * 1ll * i * i;
        cnt[i][0] %= 4;
        while (j > 0 && (j >= i || cnt[j][0] <= 1)) --j;

        // Insert check for histogram depletion inside the loop
        check_histogram_depletion(j, 1);

        if (j == 0) break;
        int add = min(cnt[j][0] / 2, cnt[i][0] / 2);
        ans += add * 1ll * i * j;
        cnt[j][0] -= add;
    }

    // Insert exhaustive pair search check before final output
    check_exhaustive_pair_search(cnt, mxn + 5);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--) solve();
}