#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n;
int a[N];
int f[N];
int sumf[N];
long long sum;
long long best;
vector<int> freq;

// Checkers for performance invariants
void check_high_frequency_invariant(const vector<int>& freq) {
    int threshold = 1000; 
    for (int i = 0; i < freq.size() - 1; ++i) {
        if (freq[i + 1] - freq[i] < threshold) {
            cerr << "Warning: Performance bottleneck condition triggered due to high frequency of closely grouped powers!" << endl;
            abort();
        }
    }
}

void check_large_freq_invariant(const vector<int>& freq) {
    if (freq.size() > 50000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large frequency list size!" << endl;
        abort();
    }
}

void check_no_power_one_invariant(const int* f) {
    if (f[1] == 0) {
        cerr << "Warning: Performance bottleneck condition triggered due to absence of power value 1!" << endl;
        abort();
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        f[a[i]]++;
        sum += a[i];
    }

    // Invariant check for absence of power value 1
    check_no_power_one_invariant(f);

    if (f[1]) {
        printf("%lld\n", sum);
        return 0;
    }
    
    for (int i = 2; i < N; i++) {
        if (f[i]) freq.push_back(i);
        sumf[i] = f[i] + sumf[i - 1];
    }

    // Invariant check for large freq size
    check_large_freq_invariant(freq);

    for (int i = 0; i < freq.size(); i++) {
        int leading = freq[i];
        long long total = 0;
        for (int j = leading; j < N; j += leading) {
            total += 1ll * (sumf[min(j + leading - 1, N - 1)] - sumf[j - 1]) * j;
        }
        best = max(best, total);
    }

    // Invariant check for high frequency of closely grouped powers
    check_high_frequency_invariant(freq);

    printf("%lld\n", best);
    return 0;
}