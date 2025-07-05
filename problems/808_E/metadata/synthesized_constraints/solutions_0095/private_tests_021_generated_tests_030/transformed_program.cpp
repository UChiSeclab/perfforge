#include <bits/stdc++.h>
using namespace std;

const int MX = 3e5 + 69;
int n, c;
long long f[MX];

struct fuck {
    long long w, c, dif;
} a[MX];

// Checker functions
void check_sorting_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - uniform weight-to-cost ratios leading to expensive sorting!" << endl;
        abort();
    }
}

void check_dp_update_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient DP table updates for large capacity!" << endl;
        abort();
    }
}

void check_uniform_weight_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - many souvenirs have the same weight!" << endl;
        abort();
    }
}

bool cmp(fuck a, fuck b) {
    return (a.dif > b.dif);
}

int main() {
    cin >> n >> c;
    map<int, int> weight_count;
    for (int i = 0; i < n; i++) {
        long long w, c;
        scanf("%I64d %I64d", &w, &c);
        a[i] = {w, c, 6 * c / w};
        weight_count[w]++;
    }

    // Check for uniform weight impact
    check_uniform_weight_invariant(any_of(weight_count.begin(), weight_count.end(), [](const pair<int, int>& p) { return p.second > n / 2; }));

    sort(a, a + n, cmp);

    // Check sorting complexity trigger
    check_sorting_invariant(n > 50000 && weight_count.size() < n / 2);

    long long k = 0;
    long long ans = 0;

    // Check dynamic programming array update
    check_dp_update_invariant(c > 250000);

    for (int i = 0; i < n; i++) {
        k += a[i].w;
        k = min(k, c * 1ll);
        for (int j = k; j >= max(a[i].w, k - 20); j--) {
            f[j] = max(f[j], f[j - a[i].w] + a[i].c);
            ans = max(ans, f[j]);
        }
    }

    cout << ans;
    return 0;
}