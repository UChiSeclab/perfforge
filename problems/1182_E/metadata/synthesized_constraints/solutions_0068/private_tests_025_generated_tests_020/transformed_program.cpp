#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const int C = 3, MOD = 1e9 + 7;
ll n;
int f1, f2, f3, c;

void check_factorization_invariant(int value) {
    int factor_count = 0;
    for (int i = 2; i * i <= value; ++i) {
        while (value % i == 0) {
            value /= i;
            ++factor_count;
        }
    }
    if (value > 1) {
        ++factor_count;
    }
    if (factor_count > 100) {
        cerr << "Warning: factorization_invariant triggered - high number of prime factors" << endl;
        abort();
    }
}

void check_exponentiation_invariant(int base, int exponent) {
    if (exponent > 100000) {
        cerr << "Warning: exponentiation_invariant triggered - large exponent" << endl;
        abort();
    }
}

void check_merging_invariant(const vector<pair<int, int>>& factors) {
    if (factors.size() > 100) {
        cerr << "Warning: merging_invariant triggered - large number of factors" << endl;
        abort();
    }
}

void check_set_invariant(const set<int>& factor_set) {
    if (factor_set.size() > 100) {
        cerr << "Warning: set_invariant triggered - large set of factors" << endl;
        abort();
    }
}

void fct(vector<pair<int, int> > &ans, int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            int c = 0;
            while (x % i == 0) x /= i, ++c;
            ans.push_back({i, c});
        }
    }
    if (x > 1) {
        ans.push_back({x, 1});
    }
    check_factorization_invariant(x); // Check factorization complexity
}

void mrg(vector<pair<int, int> > &a, vector<pair<int, int> > &b) {
    map<int, int> c;
    for (auto x : a) c[x.first] += x.second;
    for (auto x : b) c[x.first] += x.second;
    a.clear();
    for (auto x : c) a.push_back(x);
    check_merging_invariant(a); // Check merging complexity
}

inline int add(int a, int b) {
    a += b;
    if (a >= MOD - 1) a -= MOD - 1;
    return a;
}

inline int mul(int a, int b) { return ((ll)a * b) % (MOD - 1); }

int a[3][C][C], rsv = 2;

void mul(int r, int f, int s) {
    for (int i = 0; i < C; ++i) {
        for (int k = 0; k < C; ++k) {
            for (int j = 0; j < C; ++j) {
                a[rsv][i][j] = add(a[rsv][i][j], mul(a[f][i][k], a[s][k][j]));
            }
        }
    }
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            a[r][i][j] = a[rsv][i][j];
            a[rsv][i][j] = 0;
        }
    }
}

int bpow(int a, int b) {
    int ans = 1;
    check_exponentiation_invariant(a, b); // Check exponentiation overhead
    while (b != 0) {
        if (b & 1) {
            ans = ((ll)ans * a) % MOD;
        }
        b >>= 1;
        a = ((ll)a * a) % MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> f1 >> f2 >> f3 >> c;
    vector<pair<int, int> > ff1, ff2, ff3, fc;
    fct(ff1, f1), fct(ff2, f2), fct(ff3, f3), fct(fc, c);
    mrg(ff1, fc), mrg(ff2, fc), mrg(ff2, fc), mrg(ff3, fc), mrg(ff3, fc),
        mrg(ff3, fc);
    int dv = bpow(c, mul(n % (MOD - 1), MOD - 2));
    set<int> s;
    for (auto x : ff1) s.insert(x.first);
    for (auto x : ff2) s.insert(x.first);
    for (auto x : ff3) s.insert(x.first);
    check_set_invariant(s); // Check set operations complexity
    a[0][0][1] = a[0][1][2] = a[0][2][0] = a[0][2][1] = a[0][2][2] = 1;
    a[1][0][0] = a[1][1][1] = a[1][2][2] = 1;
    n -= 3;
    while (n != 0) {
        if (n & 1) {
            mul(1, 1, 0);
        }
        n >>= 1;
        mul(0, 0, 0);
    }
    int ans = 1;
    for (auto x : s) {
        int a0 = 0, a1 = 0, a2 = 0;
        for (auto y : ff1) {
            if (x == y.first) a0 = y.second;
        }
        for (auto y : ff2) {
            if (x == y.first) a1 = y.second;
        }
        for (auto y : ff3) {
            if (x == y.first) a2 = y.second;
        }
        int xx = mul(a0, a[1][2][0]), yy = mul(a1, a[1][2][1]),
            zz = mul(a2, a[1][2][2]);
        ans = ((ll)ans * bpow(x, add(xx, add(yy, zz))) % MOD);
    }
    ans = ((ll)ans * dv) % MOD;
    cout << ans << '\n';
    return 0;
}