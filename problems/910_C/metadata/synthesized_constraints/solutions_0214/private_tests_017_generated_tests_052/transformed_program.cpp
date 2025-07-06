#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7, INF = 0x3f3f3f3f;

// Functions to check performance bottlenecks
void check_permutation_condition(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive valid permutations due to leading digit constraints!" << endl;
        abort();
    }
}

void check_permutation_interaction(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive computation due to high permutation interaction!" << endl;
        abort();
    }
}

void check_frequency_utilization(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent large computations in the frequency matrix!" << endl;
        abort();
    }
}

const int N = 1e6 + 50;
int n, f[N][10], a[N], vis[N];
char s[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s + 1);
        int m = strlen(s + 1);
        for (int j = 1; j <= m; ++j) ++f[m - j + 1][s[j] - 'a'];
        vis[s[1] - 'a'] = 1;
    }
    
    for (int i = 0; i <= 9; ++i) a[i] = i;
    long long ans = 1e18;
    
    check_frequency_utilization(n > 900); // Check based on input size and frequency matrix
    
    do {
        check_permutation_condition(vis[a[0]] == 0); // Check during permutation generation
        
        long long ret = 0, now = 1;
        
        for (int i = 1; i <= 7; ++i) {
            for (int j = 1; j <= 9; ++j) ret += f[i][a[j]] * j * now;
            now *= 10;
        }
        
        ans = min(ans, ret);
        
        check_permutation_interaction(ans > 1e16); // Check for excessive work in permutations

    } while (next_permutation(a, a + 10));
    
    printf("%lld\n", ans);
}