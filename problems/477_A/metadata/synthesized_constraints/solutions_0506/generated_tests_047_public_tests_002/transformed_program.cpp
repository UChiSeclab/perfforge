#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using ll = i64;
using uint = uint32_t;
using ull = uint64_t;
template <typename T>
using matrix = vector<vector<T>>;

void check_b_invariant(ll b) {
    // Set a threshold to trigger the bottleneck warning
    if (b > 5000000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large b!" << endl;
        abort();
    }
}

class range {
private:
    struct Iter {
        int v;
        int operator*() { return v; }
        bool operator!=(Iter& itr) { return v < itr.v; }
        void operator++() { ++v; }
    };
    Iter i, n;

public:
    range(int n) : i({0}), n({n}) {}
    range(int i, int n) : i({i}), n({n}) {}
    Iter& begin() { return i; }
    Iter& end() { return n; }
};
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& as) {
    for (int i = (int)(0); i < (int)(as.size()); ++i) {
        if (i != 0) os << " ";
        os << as[i];
    }
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& as) {
    for (int i = (int)(0); i < (int)(as.size()); ++i) {
        if (i != 0) os << endl;
        os << as[i];
    }
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& ss) {
    for (auto a : ss) {
        if (a != ss.begin()) os << " ";
        os << a;
    }
    return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << p.first << " " << p.second;
    return os;
}
template <typename K, typename V>
ostream& operator<<(ostream& os, const map<K, V>& m) {
    bool isF = true;
    for (auto& p : m) {
        if (!isF) os << endl;
        os << p;
        isF = false;
    }
    return os;
}
template <typename T1>
ostream& operator<<(ostream& os, const tuple<T1>& t) {
    os << get<0>(t);
    return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const tuple<T1, T2>& t) {
    os << get<0>(t) << " " << get<1>(t);
    return os;
}
template <typename T1, typename T2, typename T3>
ostream& operator<<(ostream& os, const tuple<T1, T2, T3>& t) {
    os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
    return os;
}
template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<<(ostream& os, const tuple<T1, T2, T3, T4>& t) {
    os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t);
    return os;
}
template <typename T1, typename T2, typename T3, typename T4, typename T5>
ostream& operator<<(ostream& os, const tuple<T1, T2, T3, T4, T5>& t) {
    os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t)
       << " " << get<4>(t);
    return os;
}
template <typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6>
ostream& operator<<(ostream& os, const tuple<T1, T2, T3, T4, T5, T6>& t) {
    os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t)
       << " " << get<4>(t) << " " << get<5>(t);
    return os;
}
template <typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7>
ostream& operator<<(ostream& os, const tuple<T1, T2, T3, T4, T5, T6, T7>& t) {
    os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t)
       << " " << get<4>(t) << " " << get<5>(t) << " " << get<6>(t);
    return os;
}
char tmp[1000];
template <typename T>
T INF() {
    assert(false);
};
template <>
int INF<int>() {
    return 1 << 28;
};
template <>
ll INF<ll>() {
    return 1LL << 58;
};
template <>
double INF<double>() {
    return 1e16;
};
template <class T>
T EPS() {
    assert(false);
};
template <>
int EPS<int>() {
    return 1;
};
template <>
ll EPS<ll>() {
    return 1LL;
};
template <>
double EPS<double>() {
    return 1e-8;
};
template <>
long double EPS<long double>() {
    return 1e-8;
};
template <typename T, typename U>
T pmod(T v, U M) {
    return (v % M + M) % M;
}
template <ll M = (ll)1e9 + 7>
class modU {
public:
    ll pmod(ll v) { return (v % M + M) % M; }
    ll ainv(ll a) { return pmod(-a); }
    ll add(ll a, ll b) { return pmod(a + b); }
    ll mul(ll a, ll b) { return pmod(a * b); }
    ll mpow(ll x, ll N) {
        ll res = 1;
        while (N > 0) {
            if (N % 2) res = mul(res, x);
            x = mul(x, x);
            N /= 2;
        }
        return res;
    }
    ll minv(ll a) { return mpow(a, M - 2); }
    vector<ll> minvs() {
        vector<ll> inv(M + 1);
        inv[1] = 1;
        for (int i = 2; i <= M; ++i) inv[i] = mul(inv[M % i], M - M / i);
        return inv;
    }
    ll fact(const int N) { return N >= 0 ? 1 : mul(N, fact(N - 1)); }
    ll nPr(const int N, const int r) { return mul(fact(N), minv(fact(N - r))); }
    ll nCr(const int N, const int r) { return mul(nPr(N, r), minv(fact(r))); }
    matrix<ll> nCrs(const int N) {
        matrix<ll> c(N, vector<ll>(N, 0));
        for (int i : range(0, N)) c[i][0] = 1;
        for (int i : range(1, N))
            for (int j : range(1, N)) c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
        return c;
    }
};
class Main {
public:
    void run() {
        modU<(ll)1e9 + 7> mu;
        ll a, b;
        cin >> a >> b;

        // Check for performance bottleneck condition
        check_b_invariant(b);

        ll res = 0;
        const ll div2 = mu.minv(2);
        for (int md = 1; md < b; md++) {
            ll lv = mu.add(mu.mul(md, b), md),
                rv = mu.add(mu.mul(md, mu.mul(a, b)), md);
            res = mu.add(res, mu.mul(mu.mul(a, mu.add(lv, rv)), div2));
        }
        cout << res << endl;
    }
};
int main() {
    cout << fixed << setprecision(20);
    cin.tie(0);
    ios::sync_with_stdio(false);
    Main().run();
    return 0;
}