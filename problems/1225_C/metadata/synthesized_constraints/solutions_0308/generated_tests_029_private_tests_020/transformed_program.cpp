#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance bottlenecks
void check_large_iteration_invariant(long long p, long long n) {
    if (abs(p) >= n) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop iterations." << endl;
        abort();
    }
}

void check_binary_representation_invariant(long long n1) {
    int bit_count = 0;
    long long temp = n1;
    while (temp != 0) {
        bit_count += temp % 2;
        temp /= 2;
    }
    if (bit_count > 20) { // Arbitrary threshold for significant binary complexity
        cerr << "Warning: Performance bottleneck condition triggered - complex binary representation." << endl;
        abort();
    }
}

long long binpow(long long a, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 1)
        return binpow(a, n - 1) * a;
    else {
        long long b = binpow(a, n / 2);
        return b * b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, p, v = 0, a = -1;
    cin >> n >> p;

    // Check for potential performance bottlenecks before entering the loop
    check_large_iteration_invariant(p, n);

    for (long long i = 1; i <= 1e5; ++i) {
        long long n1 = n - p * i;
        
        // Check binary representation complexity
        check_binary_representation_invariant(n1);

        vector<long long> ans;
        while (n1 != 0) {
            ans.push_back(n1 % 2);
            n1 /= 2;
        }
        long long cont = 0, p2 = 0;
        for (long long j = 0; j < ans.size(); ++j) {
            if (ans[j] == 1) {
                p2 += 1;
                long long o = binpow(2, j);
                if (o != 1) {
                    cont += binpow(2, j) / 2;
                } else {
                    cont += 1;
                }
            }
        }
        if (cont >= i && p2 <= i) {
            a = i;
            break;
        }
    }
    cout << a;
    return 0;
}