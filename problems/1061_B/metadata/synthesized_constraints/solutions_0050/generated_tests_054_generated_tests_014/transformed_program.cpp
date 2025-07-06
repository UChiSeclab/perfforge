#include <bits/stdc++.h>
using namespace std;
long long a[100005];

void check_multiset_invariant(const std::multiset<long long>& S, long long n, long long maxi) {
    // Check if the multiset is dense (many similar values) and n is large
    if (S.size() > 10000 && n > 5000) {
        std::cerr << "Warning: Performance bottleneck condition triggered - dense multiset with large n" << std::endl;
        abort();
    }
}

void check_maxi_invariant(long long maxi, long long averageHeight) {
    // Check if maxi is significantly larger than the average height (indicative of potential slow path)
    if (maxi > 2 * averageHeight) {
        std::cerr << "Warning: Performance bottleneck condition triggered - high maximum height compared to average" << std::endl;
        abort();
    }
}

int main() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    multiset<long long> S;
    long long maxi = 0, sum = 0;
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        S.insert(a[i]);
        maxi = max(maxi, a[i]);
        sum += a[i];
    }

    // Calculate average height for invariant check
    long long averageHeight = sum / n;

    // Insert checkers after input processing
    check_multiset_invariant(S, n, maxi);  // Detects dense multisets with large n
    check_maxi_invariant(maxi, averageHeight);  // Detects high maxi compared to average

    if (n == 1 || maxi == 1) {
        printf("0\n");
        return 0;
    }
    long long pos = 1, cnt = 0;
    while (!S.empty() and pos <= maxi) {
        auto it = S.lower_bound(pos);
        if (it == S.end()) break;
        S.erase(it);
        cnt++;
        pos++;
    }
    long long res = 0;
    if (pos > maxi)
        res = sum - n;
    else
        res = sum - (maxi - cnt) - n;
    printf("%lld\n", res);
    return 0;
}