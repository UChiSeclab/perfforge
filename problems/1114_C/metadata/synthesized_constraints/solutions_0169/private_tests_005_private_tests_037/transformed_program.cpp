#include <bits/stdc++.h>
using namespace std;

// Checker function for large prime-like base
void check_large_prime_like_base(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to large prime-like base triggered!" << endl;
        abort();
    }
}

// Checker function for large base iterations
void check_large_base_iterations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to large base and excessive iterations triggered!" << endl;
        abort();
    }
}

// Checker function for imbalance between n and b
void check_imbalance_n_b(bool condition) {
    if (condition) {
        cerr << "Warning: Imbalance between n and b causing bottleneck triggered!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, b;
    cin >> n >> b;

    map<long long, long long> m;
    
    // Check for large prime-like base
    check_large_prime_like_base(b > 1e12 || (b > 1e6 && b % 2 != 0)); // Example heuristic conditions
    
    for (long long i = 2; i <= sqrt(b); i++) {
        // Check for large base iterations
        check_large_base_iterations(i == 2 && b > 1e9); // Example condition for excessive iterations

        while (b % i == 0) {
            b /= i;
            m[i] += 1;
        }
    }
    if (b > 1) m[b] += 1;

    long long ans = 1e18;
    
    // Check for imbalance between n and b
    check_imbalance_n_b(n < b && b > 1e6); // Example condition for imbalance

    for (auto i : m) {
        long long x = i.first;
        long long temp = 0;
        while (x <= n) {
            temp += n / x;
            if (x <= (n / i.first)) {
                x *= i.first;
            } else {
                break;
            }
        }
        temp /= i.second;
        ans = min(ans, temp);
    }
    cout << ans << "\n";
}