#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 233;
int a[maxn];

// Checker function for invariant #1
void check_leading_card_invariant(int leading_card, int power_count) {
    if (leading_card < 10 && power_count > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - small leading card with many divisors" << endl;
        abort();
    }
}

// Checker function for invariant #2
void check_common_divisor_invariant(int divisor_count) {
    if (divisor_count > 5000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive common divisor usage" << endl;
        abort();
    }
}

int main() {
    long long ans = 0;
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    sort(a + 1, a + 1 + n);
    a[n + 1] = 2e9;
    a[0] = -1;
    
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) continue;
        
        // Calculate the number of cards divisible by a[i]
        int power_count = 0;
        for (int k = 1; k <= n; k++) {
            if (a[k] % a[i] == 0) power_count++;
        }
        
        // Check the first invariant condition with leading card a[i]
        check_leading_card_invariant(a[i], power_count);
        
        long long j = a[i];
        long long sum = 0;
        
        while (j <= 200000) {
            int l = lower_bound(a + 1, a + 1 + n, j) - a;
            int r = lower_bound(a + 1, a + 1 + n, j + a[i]) - a;
            sum += (r - l) * (j / a[i]);
            j += a[i];
        }
        
        sum *= a[i];
        if (sum > ans) ans = sum;
    }
    
    cout << ans << endl;
    return 0;
}