#include <bits/stdc++.h>
using namespace std;

long long n, len;
long long MOD = 1000000007ll;
long long a[1111], d[1111], cache[1111][1111];

long long C(long long x, long long y) {
    if (x == y) return 1;
    if (y == 1) return x;
    if (y <= 0) return 1;
    long long &ret = cache[x][y];
    if (~ret) return ret;
    return ret = (C(x - 1, y) + C(x - 1, y - 1)) % MOD;
}

void check_combinatorial_explosion(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - combinatorial explosion!" << endl;
        abort();
    }
}

void check_inefficient_memoization(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient memoization!" << endl;
        abort();
    }
}

void check_imbalanced_distribution(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - imbalanced color distribution!" << endl;
        abort();
    }
}

int main() {
    memset(cache, -1, sizeof(cache));
    ios::sync_with_stdio(0);
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // Check for imbalanced color distribution
    for (int i = 1; i <= n; i++) {
        check_imbalanced_distribution(a[i] > 900); // Example threshold that might indicate imbalance
    }
    
    d[1] = 1;
    len = a[1];
    
    for (int i = 2; i <= n; i++) {
        // Check for combinatorial explosion before calculating
        check_combinatorial_explosion(len + a[i] - 1 > 950); // Example threshold for len + a[i]
        
        d[i] = (d[i - 1] * C(len + a[i] - 1ll, a[i] - 1ll)) % MOD;
        
        // Check for inefficient memoization
        check_inefficient_memoization(cache[len + a[i] - 1][a[i] - 1] == -1); // Example condition for cache miss
        
        len += a[i];
    }
    
    cout << d[n];
}