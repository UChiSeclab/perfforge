#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const long long inf = 1e9 + 7;
const long double eps = (long double)1e-12;
const double pi = 3.141592653;
const long long linf = 1e18 + 7;
const int logn = 20;
int n, a[maxn], tim, ans;
map<int, int> cnt;
int fir, sec;
int res;

void check_imbalance_invariant(int minPrize, int maxPrize) {
    if (std::abs(minPrize - 1) > 10 * std::abs(106 - maxPrize)) {
        cerr << "Warning: Imbalance invariant triggered - one participant may need to travel significantly more!" << endl;
        abort();
    }
}

void check_large_range_invariant(int minPrize, int maxPrize) {
    if (maxPrize - minPrize > 500000) {
        cerr << "Warning: Large range invariant triggered - large distance between closest and farthest prizes!" << endl;
        abort();
    }
}

void check_adaptive_strategy_invariant(int minPrize, int maxPrize) {
    if ((maxPrize < 1000 && minPrize < 50) || (maxPrize > 990000 && minPrize > 500000)) {
        cerr << "Warning: Adaptive strategy invariant triggered - prizes heavily skewed towards one end!" << endl;
        abort();
    }
}

int main() {
    fir = 1;
    sec = 1e6;
    cin >> n;
    int minPrize = inf, maxPrize = -inf;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]] = 1;
        res++;
        minPrize = min(minPrize, a[i]);
        maxPrize = max(maxPrize, a[i]);
    }

    // Check performance-characterizing invariants before the main loop
    check_imbalance_invariant(minPrize, maxPrize);
    check_large_range_invariant(minPrize, maxPrize);
    check_adaptive_strategy_invariant(minPrize, maxPrize);

    while (fir <= sec) {
        fir++;
        sec--;
        if (cnt[fir]) cnt[fir] = 0, res--;
        if (cnt[sec]) cnt[sec] = 0, res--;
        tim++;
        if (!res) break;
    }
    cout << tim;
    return 0;
}