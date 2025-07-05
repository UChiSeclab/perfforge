#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;

// Instrumentation check functions
void check_lesser_elements_invariant(int lesserElementsCount, int threshold) {
    if (lesserElementsCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - too many elements less than starting position!" << endl;
        abort();
    }
}

void check_modular_inverse_invariant(int modularInverseCount, int threshold) {
    if (modularInverseCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive modular inverse calculations!" << endl;
        abort();
    }
}

void check_sort_invariant(int elementCount, int threshold) {
    if (elementCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - sorting large array of potential moves!" << endl;
        abort();
    }
}

void check_equal_value_invariant(int equalValueCount, int threshold) {
    if (equalValueCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - too many equal value iterations!" << endl;
        abort();
    }
}

inline int read() {
    char ch = getchar();
    int w = 1, s = 0;
    while (!isdigit(ch)) {
        if (ch == '-') w = -1;
        ch = getchar();
    };
    while (isdigit(ch)) {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return w * s;
}

inline long long ksm(long long x, long long y) {
    long long res = 1;
    while (y) {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

inline long long rev(long long x) { return ksm(x, mod - 2); }
inline long long sqr(long long x) { return x * x % mod; }
inline long long add(long long a, long long b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

struct node {
    long long x, y, w;
} Ma[1000010];

int n, m;
long long p[1000010], mat[1010][1010], F[1000010];
inline bool cmp(node p, node q) { return p.w < q.w; }

int main() {
    n = read(), m = read();
    int cnt = 0;
    for (register int i = 1; i <= n; ++i) {
        for (register int j = 1; j <= m; ++j) {
            mat[i][j] = read();
        }
    }
    long long r = read(), c = read();
    int tmp = mat[r][c];

    // Count lesser elements for invariant checking
    int lesserElementsCount = 0;

    Ma[++cnt].w = tmp;
    Ma[cnt].x = r, Ma[cnt].y = c;
    for (register int i = 1; i <= n; ++i) {
        for (register int j = 1; j <= m; ++j) {
            if (tmp > mat[i][j]) {
                Ma[++cnt].w = mat[i][j];
                Ma[cnt].x = i, Ma[cnt].y = j;
                lesserElementsCount++;
            }
        }
    }

    // Check invariant for too many lesser elements
    check_lesser_elements_invariant(lesserElementsCount, n * m / 2);

    sort(Ma + 1, Ma + cnt + 1, cmp);

    // Check invariant for sorting large data
    check_sort_invariant(cnt, n * m / 2);

    Ma[0].w = -1e9 - 10;
    Ma[cnt + 1].w = -1e9 - 10;
    long long Sum1 = 0, Sum2 = 0, Sum3 = 0, Sum4 = 0, res = 0;
    int j = 0;

    // Count modular inverse calculations
    int modularInverseCount = 0;

    for (register int i = 1; i <= cnt; i = j + 1) {
        j = i;
        while (Ma[j + 1].w == Ma[j].w) j++;

        // Check invariant for equal values
        check_equal_value_invariant(j - i + 1, n * m / 10);

        if (i == 1) {
            for (register int k = i; k <= j; ++k) {
                F[k] = 0;
                Sum1 = add(Sum1, sqr(Ma[k].x));
                Sum2 = add(Sum2, sqr(Ma[k].y));
                Sum3 = add(Sum3, Ma[k].x);
                Sum4 = add(Sum4, Ma[k].y);
            }
            continue;
        }
        for (register int k = i; k <= j; ++k) {
            F[k] = (1ll * 
                    (sqr(Ma[k].x) + sqr(Ma[k].y) + 1ll * Sum1 * rev(i - 1) % mod +
                     1ll * Sum2 * rev(i - 1) % mod -
                     2ll * Sum3 * rev(i - 1) % mod * Ma[k].x % mod -
                     2ll * Sum4 * rev(i - 1) % mod * Ma[k].y % mod) %
                    mod +
                    mod + res * rev(i - 1) % mod) %
                   mod;

            modularInverseCount += 4; // Each term rev(i - 1) calls ksm
        }

        // Check invariant for excessive modular inverses
        check_modular_inverse_invariant(modularInverseCount, n * m);

        for (register int k = i; k <= j; ++k) {
            Sum1 = add(Sum1, sqr(Ma[k].x));
            Sum2 = add(Sum2, sqr(Ma[k].y));
            Sum3 = add(Sum3, Ma[k].x);
            Sum4 = add(Sum4, Ma[k].y);
            res = add(F[k], res);
        }
    }
    cout << F[cnt] << "\n";
    return 0;
}