#include <bits/stdc++.h>
using namespace std;

int n;
int maxa;
int a[100005];
int dp[1000005];
vector<int> d[1000005];

void sieve(int x) {
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= x / i; j++) {
            d[i * j].push_back(i);
        }
    }
}

// Checkers based on derived performance invariants

// Check for high maximum value in the array
void check_max_value_invariant(int max_value) {
    if (max_value > 900000) { // A high threshold close to the maximum constraint
        cerr << "Warning: Performance bottleneck condition triggered - maximum array value is high!" << endl;
        abort();
    }
}

// Check for high number of divisors for any element
void check_divisors_invariant(const vector<int>& divisors) {
    for (size_t i = 0; i < divisors.size(); ++i) {
        if (divisors[i] > 1000) { // Arbitrary threshold for excessive number of divisors
            cerr << "Warning: Performance bottleneck condition triggered - element has many divisors!" << endl;
            abort();
        }
    }
}

// Check for large input size combined with high array values
void check_large_input_invariant(int n, int max_value) {
    if (n > 90000 && max_value > 800000) { // Combined condition for large n and high values
        cerr << "Warning: Performance bottleneck condition triggered - large input size and high values!" << endl;
        abort();
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        maxa = max(maxa, a[i]);
    }

    // Insert check after reading inputs
    check_max_value_invariant(maxa);
    check_large_input_invariant(n, maxa);
    
    dp[0] = 1;
    sieve(maxa);
    
    for (int i = 1; i <= n; i++) {
        check_divisors_invariant(d[a[i]]);
        for (int j = d[a[i]].size() - 1; j >= 0; j--) {
            int x = d[a[i]][j];
            dp[x] += dp[x - 1];
            dp[x] %= 1000000007;
        }
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i];
    }
    ans %= 1000000007;
    cout << ans;
}