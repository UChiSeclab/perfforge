#include <bits/stdc++.h>
const double eps = 1E-9;
const double pi = acos(-1);
const long long mod = 1000000007;
using namespace std;
long long a, b;
long long x;

long long f(long long i) {
    return ((((b * i) % mod) * x) % mod + (a * i) % mod) % mod;
}

void check_loop_invariant(long long b) {
    if (b > 100000) { // Example threshold for significant slowdown
        cerr << "Warning: Performance bottleneck triggered - excessive loop iterations due to large b." << endl;
        abort();
    }
}

void check_function_call_invariant(long long iterations) {
    if (iterations > 100000) { // Example threshold for excessive function calls
        cerr << "Warning: Performance bottleneck triggered - excessive function calls." << endl;
        abort();
    }
}

int main() {
    scanf("%I64d%I64d", &a, &b);

    // Check if the loop will iterate excessively
    check_loop_invariant(b);

    x = (a * (a + 1) / 2ll) % mod;
    long long i, kq = 0, j;

    // Check if the function will be called excessively
    check_function_call_invariant(b - 1);

    for (i = 1; i < b; ++i) {
        kq = (kq + f(i)) % mod;
    }
    printf("%I64d\n", kq);
}