#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const int maxn = 2 * 1e3 + 5;
int a, n, m;
bool rain[maxn];
int um[maxn];
int f[maxn][maxn];

void check_array_initialization_invariant(int a) {
    if (a > 1800) {
        cerr << "Warning: array_initialization_invariant triggered - large array initialization overhead" << endl;
        abort();
    }
}

void check_main_loop_invariant(int a, int m) {
    if (a > 1800 && m > 1000) {
        cerr << "Warning: main_loop_invariant triggered - excessive iterations due to large `a` and many umbrellas" << endl;
        abort();
    }
}

void check_inf_values_invariant(int f[maxn][maxn], int a) {
    int inf_count = 0;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= a; ++j) {
            if (f[i][j] == inf) {
                ++inf_count;
            }
        }
    }
    if (inf_count > 0.9 * (a + 1) * (a + 1)) {
        cerr << "Warning: inf_values_invariant triggered - many entries in `f` remain `inf`" << endl;
        abort();
    }
}

int Main() {
    cin >> a >> n >> m;
    
    check_array_initialization_invariant(a);
    check_main_loop_invariant(a, m);

    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        for (int k = l; k < r; ++k) {
            rain[k] = true;
        }
    }
    for (int i = 0; i <= a; ++i) {
        um[i] = inf;
        for (int j = 0; j <= a; ++j) f[i][j] = inf;
    }
    for (int i = 0; i < m; ++i) {
        pair<int, int> u;
        cin >> u.first >> u.second;
        if (u.first < a) um[u.first] = min(um[u.first], u.second);
    }
    f[0][a] = 0;
    for (int position = 0; position < a; ++position) {
        for (int i = 0; i <= a; ++i) {
            if (f[position][i] == inf) continue;
            if (rain[position]) {
                if (i != a)
                    f[position + 1][i] = min(f[position + 1][i], f[position][i] + um[i]);
                if (um[position] != inf)
                    f[position + 1][position] =
                        min(f[position + 1][position], f[position][i] + um[position]);
            } else {
                f[position + 1][i] = min(f[position + 1][i], f[position][i] + um[i]);
                if (um[position] != inf)
                    f[position + 1][position] =
                        min(f[position + 1][position], f[position][i] + um[position]);
                f[position + 1][a] = min(f[position + 1][a], f[position][i]);
            }
        }
    }
    
    check_inf_values_invariant(f, a);

    int ans = inf;
    for (int i = 0; i <= a; ++i) {
        ans = min(f[a][i], ans);
    }
    if (ans == inf)
        cout << "-1" << endl;
    else
        cout << ans << endl;
    return 0;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    Main();
    return 0;
}