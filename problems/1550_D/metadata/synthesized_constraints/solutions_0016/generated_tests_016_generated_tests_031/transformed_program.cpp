#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#ifdef DBG
  #define dbg 1
  #define dpf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
  #define dbg 0
  #define dpf(...) 42
#endif

#define SIZE(c) int((c).size())
#define REP(i,c) for(auto &i : (c))
#define ALL(c) (c).begin(),(c).end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
typedef long long i64;
typedef unsigned long long u64;
const double EPS = 1e-12;
const int INF = 1e9 + 10;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PI;

template <typename T>
using MinPQ = priority_queue<T, vector<T>, greater<T>>;

// Checker functions based on performance-characterizing invariants
void check_gcd_invariant(int gcd_call_count, int threshold) {
    if (gcd_call_count > threshold) {
        cerr << "Warning: Performance bottleneck due to excessive GCD calculations!" << endl;
        abort();
    }
}

void check_combination_invariant(int combination_call_count, int threshold) {
    if (combination_call_count > threshold) {
        cerr << "Warning: Performance bottleneck due to excessive combination calculations!" << endl;
        abort();
    }
}

void check_loop_invariant(int loop_iteration_count, int threshold) {
    if (loop_iteration_count > threshold) {
        cerr << "Warning: Performance bottleneck due to high loop iteration count!" << endl;
        abort();
    }
}

i64 GcdExt(i64 a, i64 b, i64 &x, i64 &y) {
    static int gcd_call_count = 0; // Counter for GCD calls
    gcd_call_count++;
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    i64 d = GcdExt(b, a % b, x, y);
    i64 tmp = y;
    y = x - y * (a / b);
    x = tmp;
    // Check gcd call count after execution
    check_gcd_invariant(gcd_call_count, 1000000); // Threshold for GCD calls
    return d;
}

struct ModInt {
    static constexpr int MOD = 1e9 + 7;

    int v = 0;

    ModInt() {}
    ModInt(i64 x) {
        v = x % MOD;
        if (v < 0) v += MOD;
    }

    ModInt& operator+=(const ModInt& r) { v += r.v; if (v >= MOD) v -= MOD; return *this; }
    ModInt& operator-=(const ModInt& r) { v -= r.v; if (v < 0) v += MOD; return *this; }
    ModInt& operator*=(const ModInt& r) { v = ((i64)v * r.v) % MOD; return *this; }
    ModInt& operator/=(const ModInt& r) { *this *= r.Inv(); return *this; }

    friend ModInt operator+(ModInt l, const ModInt& r) { l += r; return l; }
    friend ModInt operator-(ModInt l, const ModInt& r) { l -= r; return l; }
    friend ModInt operator*(ModInt l, const ModInt& r) { l *= r; return l; }
    friend ModInt operator/(ModInt l, const ModInt& r) { l /= r; return l; }

    ModInt Inv() const {
        i64 x, y;
        assert(GcdExt(v, MOD, x, y) == 1);
        return x;
    }

    ModInt Pow(int n) {
        if (!n) return 1;
        ModInt r = Pow(n >> 1);
        r *= r;
        if (n & 1) r *= v;
        return r;
    }
};

ModInt fact[200001];

ModInt C(int x, int y) {
    static int combination_call_count = 0; // Counter for combination calls
    combination_call_count++;
    check_combination_invariant(combination_call_count, 1000000); // Threshold for combination calls
    if (y > x || y < 0) return 0;
    return fact[x] / fact[y] / fact[x - y];
}

int n, l, r;

ModInt Go(int m) {
    ModInt res;
    int k1 = min(1 - l, r - n);
    assert(k1 >= 0);
    res += C(n, m) * k1;

    int loop_iteration_count = 0; // Counter for loop iterations
    for (int k = k1 + 1;; ++k) {
        int x = max(1, l + k);
        int y = min(n, r - k);
        if (y - x + 1 < 0) break;
        res += C(y - x + 1, m - x + 1);
        
        loop_iteration_count++;
    }
    // Check loop iteration count after execution
    check_loop_invariant(loop_iteration_count, 1000000); // Threshold for loop iterations
    return res;
}

void Solve() {
    scanf("%d%d%d", &n, &l, &r);
    int n2 = n / 2;
    ModInt ans = Go(n2);
    if (n & 1) ans += Go(n - n2);
    printf("%d\n", ans.v);
}

int main() {
    fact[0] = 1;
    for (int i = 1; i <= 200000; ++i) fact[i] = fact[i - 1] * i;

    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        Solve();
    }

    return 0;
}