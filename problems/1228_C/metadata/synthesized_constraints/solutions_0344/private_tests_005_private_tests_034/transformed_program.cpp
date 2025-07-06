#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
long long x, n, cnt, pr[maxn];

long long quick(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

void check_prime_factorization_complexity(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to complex prime factorization!" << endl;
        abort();
    }
}

void check_exponent_calculation(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to costly exponent calculation!" << endl;
        abort();
    }
}

void check_loop_execution(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive loop execution!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cnt = 0;
    cin >> x >> n;
    long long tmp = x;
    long long primeFactorCount = 0;

    for (long long i = 2; i <= sqrt(x); i++) {
        if (tmp % i == 0) {
            pr[++cnt] = i;
            primeFactorCount++;
            while (tmp % i == 0) tmp /= i;
        }
    }
    if (tmp != 1) pr[++cnt] = tmp;
    
    // Check for prime factorization complexity
    check_prime_factorization_complexity(primeFactorCount > 10);  // Arbitrary threshold for complexity
    
    long long ans = 1;
    for (long long i = 1; i <= cnt; i++) {
        long long sum = 0;
        tmp = n;
        
        long long loopCount = 0;
        while (tmp > 0) {
            sum += (tmp / pr[i]);
            tmp /= pr[i];
            loopCount++;
        }
        
        // Check for excessive loop execution
        check_loop_execution(loopCount > 20);  // Arbitrary threshold for loop execution count

        ans = (ans * quick(pr[i], sum)) % mod;
        
        // Check for costly exponent calculation
        check_exponent_calculation(sum > 100);  // Arbitrary threshold for sum
    }
    
    cout << ans << endl;
    return 0;
}