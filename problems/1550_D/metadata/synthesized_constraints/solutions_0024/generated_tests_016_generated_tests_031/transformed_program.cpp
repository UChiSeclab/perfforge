#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

// Helper function to check combination calculation overhead
void check_combination_calculation(int range, int n) {
    if (range > n) {
        cerr << "Warning: Performance bottleneck condition triggered - High combinatorial calculation overhead!" << endl;
        abort();
    }
}

// Helper function to check repeated modular inversions
void check_modular_inversion_frequency(int inversionCount, int threshold) {
    if (inversionCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - Repeated modular inversions!" << endl;
        abort();
    }
}

// Helper function to check nested loop range
void check_nested_loop_range(int loopRange, int n) {
    if (loopRange > n) {
        cerr << "Warning: Performance bottleneck condition triggered - Nested loop excessive range!" << endl;
        abort();
    }
}

template<unsigned _MOD_> struct modint {
    static const int MOD = _MOD_;
    int v;
 
    modint(int _v = 0) {
        v = _v % MOD;
        if(v < 0) v += MOD;
    }

    explicit operator int() const { return v; }
    
    static int mod_inv(int a) {
        int g = MOD, r = a, x = 0, y = 1;
        int inversionCount = 0; // Track the number of inversions
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
            inversionCount++;
        }
        // Check if the number of inversions exceeds a threshold
        check_modular_inversion_frequency(inversionCount, 100000); // Example threshold
        return x < 0 ? x + MOD : x;
    }
 
    modint& operator+=(const modint &other) { v += other.v; if (v >= MOD) v -= MOD; return *this; }
    modint& operator-=(const modint &other) { v -= other.v; if (v < 0) v += MOD; return *this; }
    modint& operator*=(const modint &other) { v = (int)(((uint64_t) v*other.v)%MOD); return *this; }
    modint& operator/=(const modint &other) { return *this *= other.inv(); }
    friend modint operator+(const modint &a, const modint &b) { return modint(a) += b; }
    friend modint operator-(const modint &a, const modint &b) { return modint(a) -= b; }
    friend modint operator*(const modint &a, const modint &b) { return modint(a) *= b; }
    friend modint operator/(const modint &a, const modint &b) { return modint(a) /= b; }
    modint& operator++() { v = v == MOD - 1 ? 0 : v + 1; return *this; } 
    modint& operator--() { v = v == 0 ? MOD - 1 : v - 1; return *this; }
    modint operator++(int32_t) { modint before = *this; ++*this; return before; }
    modint operator--(int32_t) { modint before = *this; --*this; return before; }
    modint operator-() const { return v == 0 ? 0 : MOD - v; }
    bool operator==(const modint &other) const { return v == other.v; }
    bool operator!=(const modint &other) const { return v != other.v; }
    modint inv() const { return mod_inv(v); }
 
    modint pow(int p) const {
        modint a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &out, const modint &m) { return out << m.v; }
};

const int MOD = 1000000007;
using mint = modint<MOD>;

void solve() {
    int n, l, r; cin >> n >> l >> r;

    vector<mint> f;
    f.emplace_back(mint(1));
    int sz = 1;
    auto fac = [&](int i) -> mint {
        while(i >= sz) {
            mint nxt = f[sz-1]*sz;
            f.emplace_back(nxt);
            sz++;
        }
        return f[i];
    };
    auto choose = [&](int n, int k) -> mint {
        if(n < k || k < 0) return 0;
        return fac(n)/fac(k)/fac(n-k);
    };

    int hf = n/2;
    mint ans = 0;
    int both_all = min(1-l, r-n);
    
    // Check for high combinatorial calculation overhead
    check_combination_calculation(both_all, n);

    ans += choose(n, hf)*both_all;
    if(n & 1) {
        ans += choose(n, hf+1)*both_all;
    }

    for(int k = both_all+1; ; ++k) {
        int tp = max(0, k-(1-l));
        int bt = max(0, k-(r-n));

        // Check for excessive range in the nested loop
        check_nested_loop_range(tp + bt, n);

        if(tp+bt > n) {
            break;
        }

        ans += choose(n-tp-bt, hf-tp);
        if(n & 1) {
            ans += choose(n-tp-bt, hf+1-tp);
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}