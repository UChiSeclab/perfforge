#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_board_dimensions(long long int h, long long int w) {
    if (h > 100000 || w > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - large board dimensions!" << endl;
        abort();
    }
}

void check_high_modular_inversion_frequency(long long int maxF) {
    if (maxF > 200000) {
        cerr << "Warning: Performance bottleneck condition triggered - high frequency of modular inversion!" << endl;
        abort();
    }
}

void check_dense_black_cell_distribution(long long int blackCells) {
    if (blackCells > 1500) {
        cerr << "Warning: Performance bottleneck condition triggered - dense distribution of black cells!" << endl;
        abort();
    }
}

vector<long long int> facts;
vector<long long int> inv_facts;

long long int c(long long int n, long long int p) {
    if (p < 0 || n < p) return 0;
    return (facts[n] * inv_facts[p]) % 1000000007 * inv_facts[n - p] % 1000000007;
}

long long int pow_mod(long long int x, long long int n) {
    if (n == 0) return 1;
    if (n & 1) return x * pow_mod(x, n - 1) % 1000000007;
    long long int tmp = pow_mod(x, n / 2);
    return tmp * tmp % 1000000007;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    long long int X, Y, N;
    cin >> X >> Y >> N;
    
    // Check for large board dimensions
    check_large_board_dimensions(X, Y);
    
    facts.push_back(1);
    inv_facts.push_back(1);
    long long int maxF = X + Y + 1;
    
    // Check for high frequency of modular inversion
    check_high_modular_inversion_frequency(maxF);

    for (long long int n = 1; n <= maxF; ++n) {
        long long int f = facts[n - 1] * n % 1000000007;
        facts.push_back(f);
        inv_facts.push_back(pow_mod(f, 1000000007 - 2));
    }
    
    vector<pair<long long int, long long int> > xys;
    
    // Check for dense black cell distribution
    check_dense_black_cell_distribution(N);

    for (long long int n = 0; n < N; ++n) {
        long long int x, y;
        cin >> x >> y;
        xys.push_back(make_pair(x - 1, y - 1));
    }
    
    xys.push_back(make_pair(X - 1, Y - 1));
    sort(xys.begin(), xys.end());
    vector<long long int> dp(N + 1);
    
    for (long long int n = 0; n <= N; ++n) {
        long long int x = xys[n].first, y = xys[n].second;
        long long int tmp = c(x + y, y);
        for (long long int m = 0; m < N; ++m) {
            long long int xm = xys[m].first, ym = xys[m].second;
            if (xm <= x && ym <= y)
                tmp = (tmp + 1000000007 - dp[m] * c(x - xm + y - ym, x - xm) % 1000000007) % 1000000007;
        }
        dp[n] = tmp;
    }
    cout << dp[N] << endl;
    return 0;
}