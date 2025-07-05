#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void *wmem;

void check_large_input_combinations(int n, int m) {
    if (n + m > 3500) { // Adjust threshold based on experimentation, considering constraints
        cerr << "Warning: Performance bottleneck condition triggered due to large input combinations!" << endl;
        abort();
    }
}

void check_heavy_arithmetic_operations(int iterations) {
    if (iterations > 5000000) { // This threshold is arbitrary and should be adjusted as needed
        cerr << "Warning: Performance bottleneck due to heavy arithmetic operations in nested loops!" << endl;
        abort();
    }
}

void check_recursive_function_calls(int a, int b) {
    if (a * b > 4000000) { // Example threshold for expensive recursive function calls
        cerr << "Warning: Performance bottleneck due to inefficient recursion or nested function calls!" << endl;
        abort();
    }
}

template <class T>
inline void walloc1d(T **arr, int x, void **mem = &wmem) {
    static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    (*mem) = (void *)(((char *)(*mem)) + skip[((unsigned long long)(*mem)) & 15]);
    (*arr) = (T *)(*mem);
    (*mem) = ((*arr) + x);
}

struct mint {
    static unsigned R, RR, Rinv, W, md, mdninv;
    unsigned val;
    mint() {}
    mint(int a) { val = mulR(a); }
    mint(unsigned a) { val = mulR(a); }
    mint(long long a) { val = mulR(a); }
    mint(unsigned long long a) { val = mulR(a); }
    int get_inv(long long a, int md) {
        long long e, s = md, t = a, u = 1, v = 0;
        while (s) {
            e = t / s;
            t -= e * s;
            u -= e * v;
            swap(t, s);
            swap(u, v);
        }
        if (u < 0) {
            u += md;
        }
        return u;
    }
    void setmod(unsigned m) {
        int i;
        unsigned t;
        W = 32;
        md = m;
        R = (1ULL << W) % md;
        RR = (unsigned long long)R * R % md;
        switch (m) {
            case 104857601:
                Rinv = 2560000;
                mdninv = 104857599;
                break;
            case 998244353:
                Rinv = 232013824;
                mdninv = 998244351;
                break;
            case 1000000007:
                Rinv = 518424770;
                mdninv = 2226617417U;
                break;
            case 1000000009:
                Rinv = 171601999;
                mdninv = 737024967;
                break;
            case 1004535809:
                Rinv = 234947584;
                mdninv = 1004535807;
                break;
            case 1007681537:
                Rinv = 236421376;
                mdninv = 1007681535;
                break;
            case 1012924417:
                Rinv = 238887936;
                mdninv = 1012924415;
                break;
            case 1045430273:
                Rinv = 254466304;
                mdninv = 1045430271;
                break;
            case 1051721729:
                Rinv = 257538304;
                mdninv = 1051721727;
                break;
            default:
                Rinv = get_inv(R, md);
                mdninv = 0;
                t = 0;
                for (i = 0; i < ((int)W); i++) {
                    if (t % 2 == 0) {
                        t += md;
                        mdninv |= (1U << i);
                    }
                    t /= 2;
                }
        }
    }
    unsigned mulR(unsigned a) { return (unsigned long long)a * R % md; }
    unsigned mulR(int a) {
        if (a < 0) {
            a = a % md + md;
        }
        return mulR((unsigned)a);
    }
    unsigned mulR(unsigned long long a) { return mulR((unsigned)(a % md)); }
    unsigned mulR(long long a) {
        a %= md;
        if (a < 0) {
            a += md;
        }
        return mulR((unsigned)a);
    }
    unsigned reduce(unsigned T) {
        unsigned m = T * mdninv,
                 t = (unsigned)((T + (unsigned long long)m * md) >> W);
        if (t >= md) {
            t -= md;
        }
        return t;
    }
    unsigned reduce(unsigned long long T) {
        unsigned m = (unsigned)T * mdninv,
                 t = (unsigned)((T + (unsigned long long)m * md) >> W);
        if (t >= md) {
            t -= md;
        }
        return t;
    }
    unsigned get() { return reduce(val); }
    mint &operator+=(mint a) {
        val += a.val;
        if (val >= md) {
            val -= md;
        }
        return *this;
    }
    mint &operator-=(mint a) {
        if (val < a.val) {
            val = val + md - a.val;
        } else {
            val -= a.val;
        }
        return *this;
    }
    mint &operator*=(mint a) {
        val = reduce((unsigned long long)val * a.val);
        return *this;
    }
    mint &operator/=(mint a) { return *this *= a.inverse(); }
    mint operator+(mint a) { return mint(*this) += a; }
    mint operator-(mint a) { return mint(*this) -= a; }
    mint operator*(mint a) { return mint(*this) *= a; }
    mint operator/(mint a) { return mint(*this) /= a; }
    mint operator+(int a) { return mint(*this) += mint(a); }
    mint operator-(int a) { return mint(*this) -= mint(a); }
    mint operator*(int a) { return mint(*this) *= mint(a); }
    mint operator/(int a) { return mint(*this) /= mint(a); }
    mint operator+(long long a) { return mint(*this) += mint(a); }
    mint operator-(long long a) { return mint(*this) -= mint(a); }
    mint operator*(long long a) { return mint(*this) *= mint(a); }
    mint operator/(long long a) { return mint(*this) /= mint(a); }
    mint operator-(void) {
        mint res;
        if (val) {
            res.val = md - val;
        } else {
            res.val = 0;
        }
        return res;
    }
    operator bool(void) { return val != 0; }
    operator int(void) { return get(); }
    operator long long(void) { return get(); }
    mint inverse() {
        int a = val, b = md, t, u = 1, v = 0;
        mint res;
        while (b) {
            t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        if (u < 0) {
            u += md;
        }
        res.val = (unsigned long long)u * RR % md;
        return res;
    }
    mint pw(unsigned long long b) {
        mint a(*this), res;
        res.val = R;
        while (b) {
            if (b & 1) {
                res *= a;
            }
            b >>= 1;
            a *= a;
        }
        return res;
    }
    bool operator==(int a) { return mulR(a) == val; }
    bool operator!=(int a) { return mulR(a) != val; }
};

mint operator+(int a, mint b) { return mint(a) += b; }
mint operator-(int a, mint b) { return mint(a) -= b; }
mint operator*(int a, mint b) { return mint(a) *= b; }
mint operator/(int a, mint b) { return mint(a) /= b; }
mint operator+(long long a, mint b) { return mint(a) += b; }
mint operator-(long long a, mint b) { return mint(a) -= b; }
mint operator*(long long a, mint b) { return mint(a) *= b; }
mint operator/(long long a, mint b) { return mint(a) /= b; }

inline void rd(int &x) {
    int k, m = 0;
    x = 0;
    for (;;) {
        k = getchar();
        if (k == '-') {
            m = 1;
            break;
        }
        if ('0' <= k && k <= '9') {
            x = k - '0';
            break;
        }
    }
    for (;;) {
        k = getchar();
        if (k < '0' || k > '9') {
            break;
        }
        x = x * 10 + k - '0';
    }
    if (m) {
        x = -x;
    }
}

inline void wt_L(char a) { putchar(a); }
inline void wt_L(int x) {
    char f[10];
    int m = 0, s = 0;
    if (x < 0) {
        m = 1;
        x = -x;
    }
    while (x) {
        f[s++] = x % 10;
        x /= 10;
    }
    if (!s) {
        f[s++] = 0;
    }
    if (m) {
        putchar('-');
    }
    while (s--) {
        putchar(f[s] + '0');
    }
}

inline void wt_L(mint x) {
    int i;
    i = (int)x;
    wt_L(i);
}

struct combination_mint {
    mint *fac, *ifac;
    void init(int n, void **mem = &wmem) {
        int i;
        walloc1d(&fac, n, mem);
        walloc1d(&ifac, n, mem);
        fac[0] = 1;
        for (i = (1); i < (n); i++) {
            fac[i] = fac[i - 1] * i;
        }
        ifac[n - 1] = 1 / fac[n - 1];
        for (i = n - 2; i >= 0; i--) {
            ifac[i] = ifac[i + 1] * (i + 1);
        }
    }
    mint C(int a, int b) {
        if (b < 0 || b > a) {
            return 0;
        }
        return fac[a] * ifac[b] * ifac[a - b];
    }
    mint P(int a, int b) {
        if (b < 0 || b > a) {
            return 0;
        }
        return fac[a] * ifac[a - b];
    }
    mint H(int a, int b) {
        if (a == 0 && b == 0) {
            return 1;
        }
        if (a <= 0 || b < 0) {
            return 0;
        }
        return C(a + b - 1, b);
    }
};

char memarr[96000000];
unsigned mint::R, mint::RR, mint::Rinv, mint::W, mint::md, mint::mdninv;
int N;
int M;
mint dp1[2001][2001];
combination_mint comb;

inline mint f(int a, int b) {
    check_recursive_function_calls(a, b); // Check for inefficient recursion or nested function calls
    if (a < b) {
        return 0;
    }
    return (a - b + 1) * comb.C(a + b, b) / (a + 1);
}

int main() {
    int i, j, k, x1, x2, y1, y2;
    mint res, tmp1, tmp2;
    wmem = memarr;
    {
        mint x;
        x.setmod(998244853);
    }
    rd(N);
    rd(M);
    
    // Check for large input combinations
    check_large_input_combinations(N, M);
    
    comb.init(5000);
    res = 0;
    int iterations = 0; // To track number of iterations in loops
    
    for (i = 0; i < (N + M + 1); i++) {
        for (j = i % 2; j <= N; j += 2) {
            x1 = j + (i - j) / 2;
            y1 = (i - j) / 2;
            if (x1 < 0 || y1 < 0 || x1 > N || y1 > M) {
                continue;
            }
            x2 = y2 = 0;
            if (i < N + M) {
                x2 = N - x1;
                y2 = M - y1 - 1;
                if (y2 < 0) {
                    continue;
                }
            }
            res += j * f(x1, y1) * f(y2, x2);
            iterations++; // Increment iteration count within the nested loop
        }
    }
    
    // Check for heavy arithmetic operations
    check_heavy_arithmetic_operations(iterations);
    
    wt_L(res);
    wt_L('\n');
    return 0;
}