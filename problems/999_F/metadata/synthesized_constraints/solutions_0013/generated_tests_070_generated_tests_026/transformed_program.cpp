#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using ulint = unsigned long long;
const int N = 500 + 1;
const int K = 10 + 1;
int h[K];
int dp[N * K];
int n, k;

void check_favorite_number_distribution(int uniqueFavorites, int cardVariety) {
    if (uniqueFavorites > 50 && cardVariety > 100) { // Thresholds are broad, tailored for n and k constraints
        cerr << "Warning: Performance bottleneck condition triggered - excessive state space exploration due to many unique favorite numbers and card varieties." << endl;
        abort();
    }
}

void check_dynamic_programming_updates(int p, int c) {
    if (p * c > 2000) { // Rough threshold considering n and k constraints
        cerr << "Warning: Performance bottleneck condition triggered - excessive DP updates due to large p and c." << endl;
        abort();
    }
}

void check_nested_loop_execution(int p, int c) {
    if (p > 10 && c > 50) { // Thresholds chosen to reflect an overhead in nested loops
        cerr << "Warning: Performance bottleneck condition triggered - nested loops executing too many times." << endl;
        abort();
    }
}

int solve(int p, int c) {
    check_dynamic_programming_updates(p, c);  // Check condition before entering critical loop
    if (p == 0 || c == 0) {
        return 0;
    }
    fill(begin(dp), end(dp), 0);
    while (p--) {
        for (int i = 0; i <= c; i++) {
            for (int j = 0; j <= k; j++) {
                if (i >= j) {
                    dp[i - j] = max(dp[i - j], dp[i] + h[j]);
                }
            }
        }
    }
    return *max_element(begin(dp), end(dp));
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    map<int, int> fav, cnt;
    for (int i = 0; i < n * k; i++) {
        int c;
        cin >> c;
        cnt[c]++;
    }
    for (int i = 0; i < n; i++) {
        int f;
        cin >> f;
        fav[f]++;
    }
    for (int i = 1; i <= k; i++) {
        cin >> h[i];
    }
    
    // Perform checks after input is read
    check_favorite_number_distribution(fav.size(), cnt.size());

    int ans = 0;
    for (auto e : fav) {
        check_nested_loop_execution(e.second, cnt[e.first]);  // Check condition before entering nested loop
        ans += solve(e.second, cnt[e.first]);
    }
    cout << ans << endl;
}