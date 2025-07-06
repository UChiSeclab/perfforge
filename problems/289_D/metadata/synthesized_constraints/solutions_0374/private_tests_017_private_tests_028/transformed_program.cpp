#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int mod = 1000000007;

// Checker functions
void check_permutation_invariant(int n, int k) {
    if (k == n) {
        cerr << "Warning: Performance bottleneck condition triggered - recursive calls due to full permutations!" << endl;
        abort();
    }
}

void check_nested_iteration_invariant(int n, int k) {
    int maxIterations = 1000000;  // an arbitrary threshold for complexity estimation
    // Conceptually checking n! > maxIterations, but a practical threshold should be used
    if (k == n && n > 8) {  // factorial grows fast, we use a simpler check
        cerr << "Warning: Performance bottleneck condition triggered - excessive nested iterations!" << endl;
        abort();
    }
}

int Pow(int a, int b, int c) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * 1ll * a) % mod;
        a = (a * 1ll * a) % mod;
        b >>= 1;
    }
    return res;
}

int p[10];
int ans = 0;

void Solve(int n, int pos) {
    if (pos == n) {
        int cnt = 0, v = 0, ok = 1;
        for (int(i) = 0; (i) < (n); ++(i)) {
            v = i;
            cnt = 0;
            while (v && cnt <= n) {
                cnt++;
                v = p[v];
            }
            if (v) ok = false;
        }
        ans += ok;
    } else {
        for (int(i) = 0; (i) < (n); ++(i)) {
            p[pos] = i;
            Solve(n, pos + 1);
        }
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    // Place checks after input reading
    check_permutation_invariant(n, k);  // Check for permutation-induced recursion
    check_nested_iteration_invariant(n, k);  // Check for nested iterations

    Solve(k, 0);
    printf("%d\n", int((ans * 1ll * Pow(n - k, n - k, mod)) % mod));
    return 0;
}