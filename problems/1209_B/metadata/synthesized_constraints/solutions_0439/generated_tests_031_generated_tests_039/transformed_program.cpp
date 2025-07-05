#include <bits/stdc++.h>
using namespace std;

void check_max_time_bound(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high maximum time bound!" << endl;
        abort();
    }
}

void check_frequent_toggling(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent toggling of lights!" << endl;
        abort();
    }
}

void check_large_number_of_lights(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of lights!" << endl;
        abort();
    }
}

long long n, a, b;
long long f[105];
long long x;
char s[105];
long long B[105];
long long C[105];
long long in[105];

signed main() {
    scanf("%I64d", &n);
    scanf("%s", s);
    for (long long i = 0; i < n; i++) {
        scanf("%I64d", &B[i]);
        scanf("%I64d", &C[i]);
    }

    // Check for large number of lights
    check_large_number_of_lights(n > 90); // Threshold chosen as 90, close to maximum n

    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        in[i] = f[i] = s[i] - '0';
        if (f[i]) ans++;
    }
    long long t = 0;

    // Check for high maximum time bound before loop starts
    check_max_time_bound(500 > 450); // Threshold chosen as 450

    for (long long i = 1; i <= 500; i++) {
        t = 0;
        for (long long j = 0; j < n; j++) {
            if (i >= C[j] && (((i - C[j]) % B[j]) == 0)) f[j] ^= 1;
            if (f[j]) t++;
        }
        ans = max(ans, t);
        if (ans == n) break;
    }

    // Check for frequent toggling within observed time
    bool frequentToggling = false;
    for (long long i = 0; i < n; i++) {
        if (B[i] <= 2) { // If any light toggles too frequently (e.g. every 1 or 2 seconds)
            frequentToggling = true;
            break;
        }
    }
    check_frequent_toggling(frequentToggling);

    cout << ans << '\n';
}