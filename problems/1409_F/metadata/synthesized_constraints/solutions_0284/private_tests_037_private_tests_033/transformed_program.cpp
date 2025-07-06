#include <bits/stdc++.h>
using namespace std;

// Check functions for performance invariants
void check_high_k_invariant(int n, int k) {
    if (k > n * 0.9) { // Example threshold where k is close to n
        cerr << "Warning: Performance bottleneck condition triggered - high `k` near maximum `n`." << endl;
        abort();
    }
}

void check_large_nested_loops_invariant(int n, int k) {
    if (n > 190 && k > 190) { // Example threshold when n and k are both large
        cerr << "Warning: Nested loops with large dimensions - potential performance bottleneck." << endl;
        abort();
    }
}

void check_max_function_usage_invariant(int n, int k) {
    if (n * k > 10000) { // Example threshold for the product of n and k
        cerr << "Warning: Excessive max function evaluations in loops - performance bottleneck." << endl;
        abort();
    }
}

template <typename T>
void read(T &x) {
    x = 0;
    char ch = getchar();
    long long f = 1;
    while (!isdigit(ch)) {
        if (ch == '-') f *= -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    x *= f;
}

template <typename T, typename... Args>
void read(T &first, Args &...args) {
    read(first);
    read(args...);
}

template <typename T>
void write(T arg) {
    T x = arg;
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

template <typename T, typename... Ts>
void write(T arg, Ts... args) {
    write(arg);
    if (sizeof...(args) != 0) {
        putchar(' ');
        write(args...);
    }
}

const long long mod = 1e9 + 7;
const int N = 250;
int n, k, f[N][N][N];
char s[N], t[N];

int main() {
    read(n, k);
    scanf("%s", s);
    scanf("%s", t);

    // Applying performance checks before the main computation
    check_high_k_invariant(n, k);
    check_large_nested_loops_invariant(n, k);
    check_max_function_usage_invariant(n, k);

    memset((f), -0x3f3f3f3f, sizeof(f));
    f[0][0][0] = 0;

    for (register int i = 0; i < n; ++i) {
        for (register int j = 0; j <= k; ++j) {
            for (register int l = 0; l <= n; ++l) {
                if (f[i][j][l] == -0x3f3f3f3f) {
                    continue;
                }
                int e0 = s[i] == t[0];
                int e1 = s[i] == t[1];
                int e10 = t[0] == t[1];
                f[i + 1][j][l + e0] =
                    max(f[i + 1][j][l + e0], f[i][j][l] + (e1 ? l : 0));
                if (j < k) {
                    f[i + 1][j + 1][l + 1] =
                        max(f[i + 1][j + 1][l + 1], f[i][j][l] + (e10 ? l : 0));
                    f[i + 1][j + 1][l + e10] =
                        max(f[i + 1][j + 1][l + e10], f[i][j][l] + l);
                }
            }
        }
    }

    int ans = 0;
    for (register int i = 0; i <= k; ++i) {
        for (register int j = 0; j <= n; ++j) {
            ans = max(ans, f[n][i][j]);
        }
    }
    write(ans), putchar('\n');
    return 0;
}