#include <bits/stdc++.h>
using namespace std;

bool m[105], h[105];
int n, M, fm, fh, x;
bool dp[105][105];

void check_large_search_space(int fm, int fh, int n, int m) {
    if (fm < n / 2 && fh < m / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - Large search space with isolated groups!" << endl;
        abort();
    }
}

void check_limited_interactions(bool* m, bool* h, int n, int m) {
    int isolated_boys = 0, isolated_girls = 0;
    for (int i = 0; i < n; ++i) {
        if (!m[i]) isolated_boys++;
    }
    for (int j = 0; j < m; ++j) {
        if (!h[j]) isolated_girls++;
    }
    if (isolated_boys > n / 2 && isolated_girls > m / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - Limited interactions among initial happy individuals!" << endl;
        abort();
    }
}

void check_inefficient_iteration(int d, int iteration_limit) {
    if (d > iteration_limit) {
        cerr << "Warning: Performance bottleneck condition triggered - Inefficient early termination of iteration!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d%d", &n, &M, &fm);
    for (int i = 0; i < fm; ++i) {
        scanf("%d", &x);
        m[x] = 1;
    }
    scanf("%d", &fh);
    for (int i = 0; i < fh; ++i) {
        scanf("%d", &x);
        h[x] = 1;
    }
    
    // Check for large search space bottleneck after input
    check_large_search_space(fm, fh, n, M);
    check_limited_interactions(m, h, n, M);

    if (fm == n && fh == M) {
        puts("Yes");
        return 0;
    }
    
    int d, i, j;
    d = i = j = 0;
    
    while (d <= 2000000) {
        dp[i][j] = 1;
        if (m[i] || h[j]) {
            if (!m[i]) fm++;
            if (!h[j]) fh++;
            m[i] = h[j] = 1;
        }
        if (fm == n && fh == M) {
            puts("Yes");
            return 0;
        }
        d++;
        
        // Check for inefficient iteration at strategic points
        check_inefficient_iteration(d, 1000000); // Example threshold
        
        i = d % n;
        j = d % M;
    }
    
    if (fm == n && fh == M)
        puts("Yes");
    else
        puts("No");
    
    return 0;
}