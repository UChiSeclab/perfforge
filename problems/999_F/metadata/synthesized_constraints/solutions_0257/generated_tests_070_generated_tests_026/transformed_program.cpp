#include <bits/stdc++.h>
using namespace std;

long long power(long long x, long long y, long long m);
long long modInverse(long long n, long long m);
long long nCr(long long n, long long r, long long m);
long long ceiling(long long x, long long y);
bool sortbyth(const tuple<long long, int, int>& a,
              const tuple<long long, int, int>& b) {
    if (get<0>(a) != get<0>(b))
        return get<0>(a) > get<0>(b);
    else
        return get<1>(a) < get<1>(b);
}

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

// Checker function for DP table size
void check_dp_table_size(long long n, long long k) {
    if (n >= 500 && k >= 10) {
        cerr << "Warning: Performance bottleneck condition triggered - large DP table size!" << endl;
        abort();
    }
}

// Checker function for unique card values
void check_unique_card_values(const map<long long, long long>& cf, long long n) {
    if (cf.size() > n) {
        cerr << "Warning: Performance bottleneck condition triggered - too many unique card values!" << endl;
        abort();
    }
}

// Checker function for DP table access frequency
void check_dp_access_frequency(long long n, long long k) {
    if (n * k > 2500) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive DP table accesses!" << endl;
        abort();
    }
}

void aksayushx() {
    long long n, k;
    cin >> n >> k;
    
    // Check for large DP table size
    check_dp_table_size(n, k);

    vector<long long> cards(n * k);
    for (long long i = 0; i < n * k; i++) cin >> cards[i];
    vector<long long> f(n), h(k);
    for (long long i = 0; i < n; i++) cin >> f[i];
    for (long long i = 0; i < k; i++) cin >> h[i];
    
    vector<vector<long long>> dp(n + 1, vector<long long>(k * n + 1, -1));
    for (long long i = 0; i <= k * n; i++) dp[0][i] = 0;
    for (long long i = 0; i <= n; i++) dp[i][0] = 0;
    
    // Check for excessive DP table accesses
    check_dp_access_frequency(n, k);
    
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= k * n; j++) {
            for (long long give = 0; give <= k; give++) {
                if (give > j) break;
                long long happiness = give == 0 ? 0 : h[give - 1];
                happiness += dp[i - 1][j - give];
                dp[i][j] = max(dp[i][j], happiness);
            }
        }
    }
    
    map<long long, long long> cf, pf;
    for (long long i = 0; i < n; i++) pf[f[i]]++;
    for (long long i = 0; i < n * k; i++) cf[cards[i]]++;

    // Check for too many unique card values
    check_unique_card_values(cf, n);

    long long ans = 0;
    for (auto& e : cf) {
        long long cardsav = e.second;
        long long people = pf[e.first];
        ans += dp[people][cardsav];
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while (t--) aksayushx();
    return 0;
}

long long power(long long x, long long y, long long m) {
    long long res = 1;
    x = x % m;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % m;
        y = y >> 1;
        x = (x * x) % m;
    }
    return res;
}

long long modInverse(long long n, long long m) { return power(n, m - 2, m); }
long long ceiling(long long x, long long y) { return (x + y - 1) / y; }