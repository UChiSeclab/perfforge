#include <bits/stdc++.h>
using namespace std;

int count_bit(long long x) {
    if (x < 0) {
        return -1;
    }
    int ans = 0;
    while (x) {
        ans += (x & 1);
        x >>= 1;
    }
    return ans;
}

void check_large_p_small_n(long long n, long long p) {
    if (p > n) {
        cerr << "Warning: Performance bottleneck condition triggered - large p with small n!" << endl;
        abort();
    }
}

void check_loop_exceeds_limit(int x) {
    if (x >= 5000000) {
        cerr << "Warning: Performance bottleneck condition triggered - loop count very high!" << endl;
        abort();
    }
}

void check_insufficient_power_combinations(long long n, long long p, int x) {
    long long m = n - p * x;
    if (x == 5000000 && !(m >= x && __builtin_popcountll(m) <= x)) {
        cerr << "Warning: Performance bottleneck condition triggered - insufficient power combinations!" << endl;
        abort();
    }
}

int main() {
    long long n, p;
    cin >> n >> p;
    
    // Insert check to detect large p with small n
    check_large_p_small_n(n, p);
    
    for (int x = 1; x < 5000000; ++x) {
        long long m = n - p * x;
        
        // Insert check to detect loop exceeding practical limits
        check_loop_exceeds_limit(x);
        
        if (m >= x && count_bit(m) <= x) {
            cout << x << endl;
            return 0;
        }
    }
    
    // Insert check to detect insufficient power combinations at loop's limit
    check_insufficient_power_combinations(n, p, 5000000);
    
    cout << -1 << endl;
    return 0;
}