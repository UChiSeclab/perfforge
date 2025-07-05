#include <bits/stdc++.h>
using namespace std;

int a, m;

void check_coprime_invariant(int a, int m) {
    // Check if a and m are co-prime
    if (__gcd(a, m) == 1) {
        cerr << "Warning: Performance bottleneck condition triggered - a and m are co-prime!" << endl;
        abort();
    }
}

void check_slow_modulo_operation(int a, int m) {
    // Check for slow modulo operation condition
    if ((2 * a) % m != 0 && a < m && __gcd(a, m) == 1) {
        cerr << "Warning: Performance bottleneck condition triggered - slow modulo operation!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> m;

    // Check for performance bottlenecks before entering the loop
    check_coprime_invariant(a, m);
    check_slow_modulo_operation(a, m);
    
    for (int i = 1; i <= 10000000; i++) {
        a = (a + a) % m;
        if (a == 0) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}