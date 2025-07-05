#include <bits/stdc++.h>
using namespace std;

void check_memory_invariant(int maxn) {
    if (maxn > 50000) {  // Assume 50000 as a large threshold for demonstration
        cerr << "Warning: Performance bottleneck condition triggered - memory allocation for large maxn!" << endl;
        abort();
    }
}

void check_divisors_invariant(int maxn) {
    if (maxn > 50000) {  // Assume divisors increase complexity significantly
        cerr << "Warning: Performance bottleneck condition triggered - excessive computations due to large maxn divisors!" << endl;
        abort();
    }
}

void check_unique_elements_invariant(const vector<int>& a) {
    unordered_set<int> unique_elements(a.begin(), a.end());
    int maxn = *std::max_element(a.begin(), a.end());
    if (unique_elements.size() < 10 && maxn > 50000) {  // Arbitrary low unique threshold and large maxn
        cerr << "Warning: Performance bottleneck condition triggered - few unique but large elements!" << endl;
        abort();
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::istream_iterator<int> cit(std::cin);
    n = *cit++;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = *cit++;
    
    const int maxn = *std::max_element(a.begin(), a.end());
    
    // Insert invariant checks
    check_memory_invariant(maxn);
    check_divisors_invariant(maxn);
    check_unique_elements_invariant(a);
    
    // Original program logic
    p2 = new int[n + 1];
    p2[0] = 1;
    for (int i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] * 2;
        if (p2[i] > 1000000007) p2[i] -= 1000000007;
    }
    dp = new int[maxn + 1]();
    cnt = new int[maxn + 1]();
    for (int i = 0; i < n; i++) cnt[a[i]]++;
    for (int i = maxn, sum; i; i--) {
        sum = 0;
        for (int j = i; j <= maxn; j += i) sum = (sum + cnt[j]) % 1000000007;
        dp[i] = p2[sum] - 1;
        for (int j = 2 * i; j <= maxn; j += i)
            dp[i] = (dp[i] - dp[j] + 1000000007) % 1000000007;
    }
    std::cout << dp[1] << '\n';
    return 0;
}