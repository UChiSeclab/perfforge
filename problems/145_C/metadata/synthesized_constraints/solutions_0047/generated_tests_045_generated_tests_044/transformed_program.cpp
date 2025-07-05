#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, yuzu = 1e5;
typedef long long fuko[yuzu | 10];
fuko dp[2], jic = {1}, inv;
map<long long, int> mp;

long long kasumi(long long a, long long b = mod - 2) {
    long long s = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) s = s * a % mod;
    return s;
}

long long zuhe(int n, int m) {
    return jic[n] * inv[m] % mod * inv[n - m] % mod;
}

bool judge(int x) {
    return x < 10 ? x == 4 || x == 7
                  : judge(x / 10) & (x % 10 == 4 || x % 10 == 7);
}

void check_unique_lucky_invariant(int uniqueLuckyCount) {
    if (uniqueLuckyCount > 10) {  // Example threshold
        cerr << "Warning: unique_lucky_invariant triggered - too many unique lucky numbers" << endl;
        abort();
    }
}

void check_lucky_multiplicity_invariant(int multiplicity) {
    if (multiplicity > 50) {  // Example threshold
        cerr << "Warning: lucky_multiplicity_invariant triggered - high multiplicity of lucky numbers" << endl;
        abort();
    }
}

void check_combination_count_invariant(int unluckyCount) {
    if (unluckyCount > 80) {  // Example threshold
        cerr << "Warning: combination_count_invariant triggered - high combinations due to lucky numbers" << endl;
        abort();
    }
}

int main() {
    int i, n, k, cnt = 0, t = 1;
    scanf("%d%d", &n, &k);
    for (i = 1; i <= yuzu; ++i) jic[i] = jic[i - 1] * i % mod;
    inv[yuzu] = kasumi(jic[yuzu]);
    for (i = yuzu - 1; ~i; --i) inv[i] = inv[i + 1] * (i + 1) % mod;

    for (i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        judge(x) ? mp[x]++ : cnt++;
    }

    // Check unique lucky numbers invariant
    check_unique_lucky_invariant(mp.size());

    // Check multiplicity of lucky numbers invariant
    for (const auto& entry : mp) {
        check_lucky_multiplicity_invariant(entry.second);
    }

    // Check high combination count invariant
    check_combination_count_invariant(n - cnt);

    dp[1][0] = 1;
    for (i = 0; i <= cnt; ++i) dp[0][i] = zuhe(cnt, i);
    for (auto p : mp) {
        for (i = 1; i <= yuzu; ++i)
            dp[t][i] = (p.second * dp[!t][i - 1] + dp[!t][i]) % mod;
        t = !t;
    }
    cout << dp[!t][k];
}