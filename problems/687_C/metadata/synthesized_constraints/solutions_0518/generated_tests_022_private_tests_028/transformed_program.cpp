#include <bits/stdc++.h>
using namespace std;

template <class t>
inline t read(t &x) {
    char c = getchar();
    bool f = 0;
    x = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    if (f) x = -x;
    return x;
}

template <class t>
inline void write(t x) {
    if (x < 0)
        putchar('-'), write(-x);
    else {
        if (x > 9) write(x / 10);
        putchar('0' + x % 10);
    }
}

// Performance-checker functions
void check_large_coin_invariant(int max_coin_value, int m) {
    if (max_coin_value >= 450 && m >= 450) {
        cerr << "Warning: Performance bottleneck condition triggered due to large coin values combined with high target sum!" << endl;
        abort();
    }
}

void check_iteration_invariant(int n, int max_coin_value) {
    if (n > 450 && max_coin_value > 450) {
        cerr << "Warning: Performance bottleneck condition triggered due to high iteration counts in nested loops!" << endl;
        abort();
    }
}

void check_diverse_coin_invariant(const vector<int>& coins) {
    set<int> unique_coins(coins.begin(), coins.end());
    if (unique_coins.size() == coins.size() && coins.size() > 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to diverse coin set compositions!" << endl;
        abort();
    }
}

const int N = 505;
int n, m, ans, f[N][N];

signed main() {
    read(n);
    read(m);

    vector<int> coins(n);
    int max_coin_value = 0;

    for (int i = 0; i < n; ++i) {
        read(coins[i]);
        max_coin_value = max(max_coin_value, coins[i]);
    }

    // Insert checks after reading inputs
    check_large_coin_invariant(max_coin_value, m);
    check_iteration_invariant(n, max_coin_value);
    check_diverse_coin_invariant(coins);

    f[0][0] = 1;
    for (int i = 1, x; i <= n; i++) {
        x = coins[i-1];
        for (int j = m; j >= x; j--)
            for (int k = 500; k >= 0; k--) {
                if (k >= x) f[j][k] |= f[j - x][k - x];
                f[j][k] |= f[j - x][k];
            }
    }
    
    for (int i = 0; i <= m; i++)
        if (f[m][i]) ans++;
    write(ans);
    puts("");
    for (int i = 0; i <= m; i++)
        if (f[m][i]) write(i), putchar(' ');
}