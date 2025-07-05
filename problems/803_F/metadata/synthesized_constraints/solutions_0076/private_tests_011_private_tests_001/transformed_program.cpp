#include <bits/stdc++.h>
using namespace std;

// Checker function for high exponentiation overhead
void check_exponentiation_invariant(long long int exponent) {
    if (exponent > 100000) {  // Threshold based on maximum input constraints
        cerr << "Warning: Performance bottleneck condition triggered - high exponentiation overhead!" << endl;
        abort();
    }
}

// Checker function for excessive loop iterations due to maximum element
void check_iteration_invariant(int maxElement) {
    if (maxElement > 100000) {  // Threshold based on maximum element constraints
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop iterations due to large max element!" << endl;
        abort();
    }
}

// Checker function for intensive GCD-related calculations
void check_gcd_invariant(int numOccurrences) {
    if (numOccurrences > 100000) {  // Threshold based on potential heavy gcd calculations
        cerr << "Warning: Performance bottleneck condition triggered - intensive GCD-related calculations!" << endl;
        abort();
    }
}

long long int quick_pow(long long int a, long long int b, long long int MOD) {
    check_exponentiation_invariant(b);  // Check for high exponentiation overhead
    long long int ans = 1;
    long long int base = a;
    while (b) {
        if (b & 1) {
            ans = ans * base % MOD;
        }
        b >>= 1;
        base = base * base % MOD;
    }
    return ans;
}

const int maxn = 2e6 + 20;
int ans[maxn], num[maxn];
const int MOD = 1e9 + 7;

void work() {
    int n, k;
    scanf("%d", &n);
    int mx = -(0x3f3f3f3f);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        num[x]++;
        mx = max(mx, x);
    }
    
    check_iteration_invariant(mx);  // Check for excessive loop iterations due to maximum element

    long long int res = 0;
    if (num[0]) {
        ans[0] = (quick_pow(2, num[0], MOD) - 1 + MOD) % MOD;
        res = ans[0];
    }
    
    for (int i = mx; i >= 1; --i) {
        int has = num[0];
        for (int j = i; j <= mx; j += i) has += num[j];
        
        check_gcd_invariant(has);  // Check for intensive GCD-related calculations

        ans[i] = (quick_pow(2, has, MOD) - 1 + MOD) % MOD;
        for (int j = 2 * i; j <= mx; j += i) {
            ans[i] = (ans[i] - ans[j] + MOD) % MOD;
        }
        ans[i] = (ans[i] - ans[0] + MOD) % MOD;
        res = (res + quick_pow(i, k, MOD) * ans[i] % MOD) % MOD;
    }
    cout << ans[1] << endl;
    for (int i = 0; i <= mx; ++i) ans[i] = num[i] = 0;
}

int main() {
    work();
    return 0;
}