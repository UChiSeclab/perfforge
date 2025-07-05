#include <bits/stdc++.h>
using namespace std;

int n, k;
long long f[500005];
const int oo = 998244353;

bool isPrime(int u) {
    if (u <= 1) return false;
    for (int i = 2; i * i <= u; i++)
        if (u % i == 0) return false;
    return true;
}

long long pow(long long a, long long n, long long m) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long tg = pow(a, n / 2, m);
        return tg * tg % m;
    }
    return pow(a, n - 1, m) * a % oo;
}

long long inverseModule(long long a, long long m) {
    return pow(a, m - 2, m);
}

long long divideModule(long long a, long long b, long long m) {
    return a * inverseModule(b, m) % m;
}

long long C(int n, int k) {
    return divideModule(divideModule(f[n], f[k], oo), f[n - k], oo);
}

void input() {
    cin >> n >> k;
    f[0] = 1;
    
    // Check for large loop invariant before factorial computation
    check_large_loop_invariant(n > 100000); // Assuming large n results in heavy computation
    
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % oo;
    
    long long res = 0;
    
    for (int i = 1; i <= n; i++) {
        if (i * k <= n) {
            // Check for frequent combination calculations
            check_combination_invariant((n / i - 1) * (k - 1) > 100000); // Simplified condition based on frequency
            
            res = (res + C(n / i - 1, k - 1)) % oo;
        } else {
            break;
        }
    }
    cout << res;
}

void solve() {}

int main() {
    input();
    solve();
}