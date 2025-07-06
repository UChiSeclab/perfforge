#include <bits/stdc++.h>
using namespace std;

const int inf = 2000000000;
const long long infLL = 9000000000000000000;

// Checkers for performance bottlenecks
void check_large_prime_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered - large prime number detected!" << endl;
        abort();
    }
}

void check_near_prime_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered - near prime composite number detected!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // Checking for large prime or near-prime composite numbers
        bool isLargePrimeOrNearPrime = true;
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                isLargePrimeOrNearPrime = false;
                break;
            }
        }
        check_large_prime_invariant(isLargePrimeOrNearPrime && n > 100000);
        check_near_prime_invariant(isLargePrimeOrNearPrime && n <= 100000);

        if (n % 2 == 0) {
            cout << n + 2 * k << '\n';
            continue;
        }
        long long hmm;
        for (int i = 2; i <= n; ++i) {
            if (n % i == 0) {
                hmm = i;
                break;
            }
        }
        n += hmm;
        long long ans = n + (k - 1) * 2;
        cout << ans << '\n';
    }
}