#include <bits/stdc++.h>
#pragma optimize("O3")
using namespace std;
const long long MOD = 998244353;
const long long INF = 1e9 + 7;
const int base = 2e5 + 1;
const int MAX = 1e5 + 2;
const double EPS = 1e-9;
const double PI = acos(-1.);
const int MAXN = 3 * 1e5 + 47;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void check_large_difference(long long t, long long x, long long y) {
    if (min(x, y) - t > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - large score difference!" << endl;
        abort();
    }
}

void check_high_final_scores(long long x, long long y) {
    if (x > 1e8 && y > 1e8) {
        cerr << "Warning: Performance bottleneck condition triggered - very high final scores!" << endl;
        abort();
    }
}

void check_high_draw_frequency(long long draws) {
    if (draws > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - high draw frequency!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    vector<long long> x(n), y(n);
    for (long long i = 0; i < n; ++i) cin >> x[i] >> y[i];
    
    long long cnt = 0;
    long long t = 0;
    
    check_high_final_scores(x[n-1], y[n-1]);  // Check high final scores at the beginning
    
    for (long long i = 0; i < n; ++i) {
        while (t <= min(x[i], y[i])) {
            check_large_difference(t, x[i], y[i]);  // Check large difference before incrementing
            t++;
            cnt++;
            check_high_draw_frequency(cnt);  // Check high frequency of draws
        }
        t = max(t, max(x[i], y[i]));
    }
    cout << cnt;
    cerr << "\nTime elapsed: " << clock() / (double)CLOCKS_PER_SEC << '\n';
    return 0;
}