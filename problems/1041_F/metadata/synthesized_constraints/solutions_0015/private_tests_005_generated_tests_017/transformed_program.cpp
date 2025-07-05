#include <bits/stdc++.h>
using namespace std;

int A[100005], B[100005];
map<int, int> ma, maa;

void check_modulo_density(int n, int m, int mod_value, const map<int, int>& map1, const map<int, int>& map2) {
    for (const auto& x : map1) {
        if (x.second > n / 10) { // Assume a threshold of 10 for demonstration
            cerr << "Warning: Performance bottleneck condition triggered - high density of sensors in a modulo class!" << endl;
            abort();
        }
    }
    for (const auto& x : map2) {
        if (x.second > m / 10) { // Assume a threshold of 10 for demonstration
            cerr << "Warning: Performance bottleneck condition triggered - high density of sensors in a modulo class!" << endl;
            abort();
        }
    }
}

void check_map_operations(int op_count, int threshold) {
    if (op_count > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive map operations!" << endl;
        abort();
    }
}

void check_matching_density(int match_count, int threshold) {
    if (match_count > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive matching sensor positions!" << endl;
        abort();
    }
}

int main(void) {
    int i, j, k, n, m, nn, mm, ans, res, pos, L, LL, beg, mod;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d", A + i);
    }
    scanf("%d %d", &nn, &mm);
    for (i = 0; i < nn; i++) {
        scanf("%d", B + i);
    }
    ans = 2;
    int operation_threshold = 1000; // Example threshold for map operations
    for (pos = 1; pos < 1e9; pos <<= 1) {
        ma.clear();
        maa.clear();
        mod = pos * 2;
        for (i = 0; i < n; i++) {
            ma[A[i] % mod]++;
        }
        for (i = 0; i < nn; i++) {
            maa[B[i] % mod]++;
        }
        
        // Check for high density of sensors in modulo classes
        check_modulo_density(n, nn, mod, ma, maa);
        
        int map_operations = 0;
        int matches = 0;
        
        for (auto x : ma) {
            map_operations++;
            matches += x.second + maa[x.first + pos];
            ans = max(ans, x.second + maa[x.first + pos]);
        }
        
        for (auto x : maa) {
            map_operations++;
            matches += x.second + ma[x.first + pos];
            ans = max(ans, x.second + ma[x.first + pos]);
        }
        
        // Check for excessive map operations
        check_map_operations(map_operations, operation_threshold);
        
        // Check for excessive matching sensor positions
        check_matching_density(matches, operation_threshold);
    }
    printf("%d\n", ans);
}