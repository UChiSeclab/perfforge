#include <bits/stdc++.h>
using namespace std;

long long int fact[1000000];
long long int inv[1000000];

long long int ModPow(long long int base, long long int exp) {
    check_recursive_exponentiation(base, exp);
    if (exp == 0) return 1;
    if (exp % 2 == 1) return (base * ModPow(base, exp - 1)) % 1000000007;
    long long int a = ModPow(base, exp / 2);
    return (a * a) % 1000000007;
}

long long int comb(int a, int b) {
    check_combinatorial_calculations(a, b);
    if (a < 0 || b < 0) return 0;
    long long int ans = fact[a + b];
    ans *= inv[a];
    ans %= 1000000007;
    ans *= inv[b];
    ans %= 1000000007;
    return ans;
}

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    check_array_initialization_overhead(h, w);

    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < h + w + 7; i++) {
        fact[i] = i * fact[i - 1];
        fact[i] %= 1000000007;
        inv[i] = ModPow(i, 1000000007 - 2) * inv[i - 1];
        inv[i] %= 1000000007;
    }

    pair<int, int> cells[n + 2];
    cells[0] = pair<int, int>(1, 1);
    for (int i = 1; i < n + 1; i++) cin >> cells[i].first >> cells[i].second;
    cells[n + 1] = pair<int, int>(h, w);
    sort(cells, cells + n + 2);

    long long int DP[n + 2];
    DP[0] = 0;
    for (int i = 1; i < n + 2; i++) {
        DP[i] = comb(cells[i].first - 1, cells[i].second - 1);
        for (int j = 0; j < i; j++) {
            long long int can = DP[j] * comb(cells[i].first - cells[j].first,
                                             cells[i].second - cells[j].second);
            can %= 1000000007;
            DP[i] -= can;
            DP[i] += 1000000007;
            DP[i] %= 1000000007;
        }
    }

    cout << DP[n + 1] << endl;
    return 0;
}