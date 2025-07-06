#include <bits/stdc++.h>
using namespace std;
int a, b, k;
bool prime[1000001];

void check_large_range_invariant(int a, int b) {
    if ((b - a + 1) > 100000) {  // Arbitrary threshold for demonstration.
        cerr << "Warning: Performance bottleneck condition triggered due to large range size." << endl;
        abort();
    }
}

void check_high_primality_requirement(int cnt, int k) {
    if (cnt < k) {
        cerr << "Warning: Performance bottleneck condition triggered due to high primality requirement." << endl;
        abort();
    }
}

void check_prime_check_efficiency(int rangeSize, long long primeChecks) {
    if (primeChecks > rangeSize * 50) {  // Arbitrary multiplier based on expected operations.
        cerr << "Warning: Performance bottleneck condition triggered due to inefficient prime checks." << endl;
        abort();
    }
}

int main() {
    int i, j;
    cin >> a >> b >> k;
    int cnt = 0, leng = 0;
    long long primeChecks = 0;  // Counter for prime check efficiency.
    
    check_large_range_invariant(a, b);  // Check 1: Large range size.

    for (i = a; i <= b; i++) {
        prime[i] = true;
        int s = (int)(sqrt((double)i));
        for (j = 2; j <= s; j++) {
            primeChecks++;  // Increment for each divisor check.
            if (i % j == 0) {
                prime[i] = false;
                break;
            }
        }
        if (i == 1) prime[i] = false;
        if (prime[i]) cnt++;
    }
    
    check_high_primality_requirement(cnt, k);  // Check 2: High primality requirement.
    check_prime_check_efficiency(b - a + 1, primeChecks);  // Check 3: Prime check efficiency.

    if (cnt < k) {
        cout << -1;
        return 0;
    }

    int s = a, e = a, max = 0, cprime = 0;
    while (1) {
        if (e > b) break;
        if (prime[e] != true) {
            if (cprime == k) {
                if (prime[s] != true) {
                    s++;
                } else {
                    e++;
                }
            } else {
                e++;
            }
        } else if (prime[e] == true) {
            if (cprime < k) {
                cprime++;
                if (max < e - s + 1) max = e - s + 1;
                e++;
            } else if (cprime == k) {
                if (max < e - s) max = e - s;
                if (prime[s] != true) {
                    s++;
                } else {
                    if (s == e)
                        e++;
                    else {
                        if (prime[s] == true) cprime--;
                        s++;
                    }
                }
            }
        }
    }
    if (max < e - s) max = e - s;
    cout << max;
    return 0;
}