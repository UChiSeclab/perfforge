#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance bottlenecks
void check_toggle_frequency(long long totalIterations, long long threshold) {
    if (totalIterations > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive toggle iterations!" << endl;
        abort();
    }
}

void check_nested_loop(long long togglesPerLight, long long maxToggles) {
    if (togglesPerLight > maxToggles) {
        cerr << "Warning: Performance bottleneck condition triggered - heavy nested loop operations!" << endl;
        abort();
    }
}

void check_toggle_density(long long overlappingToggles, long long densityThreshold) {
    if (overlappingToggles > densityThreshold) {
        cerr << "Warning: Performance bottleneck condition triggered - high toggle density!" << endl;
        abort();
    }
}

void cases() {
    long long n, i, ans = 0, j, tg[200005] = {0}, k;
    string a;
    cin >> n >> a;
    for (i = 0; i < n; i++) a[i] -= '0';

    long long totalIterations = 0;
    long long maxToggles = 0;
    
    for (k = 0; k < n; k++) {
        long long x, y;
        cin >> x >> y;
        
        long long togglesPerLight = 0;
        
        for (i = 0; i < y; i++) tg[i] += a[k];
        a[k] = 1 - a[k];
        
        for (i = y; i < 200005; i += x) {
            tg[i] += a[k];
            if (a[k]) {
                togglesPerLight++;
                for (long long temp = i + 1; temp < i + x and temp < 200005; temp++) {
                    tg[temp]++;
                }
            }
            a[k] = 1 - a[k];
            totalIterations++;
        }
        
        maxToggles = max(maxToggles, togglesPerLight);
    }

    // Insert checks after handling all light toggles to avoid overhead in tight loops
    check_toggle_frequency(totalIterations, 500000); // Example threshold for total iterations
    check_nested_loop(maxToggles, 50); // Example threshold for nested loop operations

    long long overlappingToggles = 0;
    for (auto i : tg) overlappingToggles = max(overlappingToggles, i);
    check_toggle_density(overlappingToggles, 100); // Example threshold for toggle density

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cases();
    return 0;
}