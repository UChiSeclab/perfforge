#include <bits/stdc++.h>
using namespace std;
const long long int maxN = 100005;

void check_nested_loop_invariant(int n) {
    if (n > 900) {  // Using 900 as a threshold to indicate large n values.
        std::cerr << "Warning: Performance bottleneck condition triggered by large 'n' in nested loops!" << std::endl;
        abort();
    }
}

void check_power_function_calls(int powerCalls) {
    if (powerCalls > 1000000) {  // Indicating excessive calls to the power function.
        std::cerr << "Warning: Performance bottleneck condition triggered by excessive power function calls!" << std::endl;
        abort();
    }
}

void check_combinatorial_calculations(int n, int m) {
    if (n > 900 && m == 1) {  // Large 'n' and specific 'm' indicating heavy combinatorial calculations.
        std::cerr << "Warning: Performance bottleneck condition triggered by extensive combinatorial calculations!" << std::endl;
        abort();
    }
}

long long int power(long long int x, long long int y, long long int m) {
    static int powerCalls = 0;
    powerCalls++;
    check_power_function_calls(powerCalls);

    if (y == 0) return 1;
    long long int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0) ? p : (x * p) % m;
}

long long int modInverse(long long int a) {
    return power(a, 1000000007 - 2, 1000000007);
}

long long int factorials[maxN];
void fact(long long int n) {
    factorials[0] = 1;
    long long int i = 1;
    while (i <= n) {
        factorials[i] = (factorials[i - 1] * i) % 1000000007;
        i++;
    }
}

long long int ncr(long long int n, long long int r) {
    return factorials[n] *
           modInverse((factorials[r] * (factorials[n - r])) % 1000000007) %
           1000000007;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    long long int n, m;
    fact(10000);
    cin >> n >> m;

    // Check conditions before entering the nested loops
    check_nested_loop_invariant(n);
    check_combinatorial_calculations(n, m);

    long long int i, j, ans = 0, z = 0;
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            ans += ((ncr(i + m - 2, max(z, m - 1)) % 1000000007) *
                    (ncr(n - j + m - 1, max(z, m - 1)) % 1000000007)) %
                   1000000007;
            ans = ans % 1000000007;
        }
    }
    cout << ans;
    return 0;
}