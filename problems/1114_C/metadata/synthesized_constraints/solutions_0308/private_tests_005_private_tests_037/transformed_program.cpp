#include <bits/stdc++.h>
using namespace std;

long long n, m;
map<long long, long long> p;

long long get(long long n, long long u) {
    long long res = 0;
    while (n >= u) {
        res += n / u;
        n /= u;
    }
    return res;
}

void init(long long n) {
    long long iterationCount = 0; // Track the number of iterations in the loop
    for (long long i = 2; i <= sqrt(n);) {
        ++iterationCount; // Increment iteration count
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                p[i]++;
            }
        } else {
            ++i;
        }
    }
    if (n != 1) p[n]++;
    
    // Check for performance bottlenecks
    check_large_prime_invariant(n, iterationCount);
    check_near_max_prime_invariant(n, iterationCount);
}

int main() {
    cin >> n >> m;
    init(m);
    long long ans = (long long)1000000000000000000;
    for (auto it : p) {
        ans = min(ans, get(n, it.first) / it.second);
    }
    cout << ans;
    return 0;
}