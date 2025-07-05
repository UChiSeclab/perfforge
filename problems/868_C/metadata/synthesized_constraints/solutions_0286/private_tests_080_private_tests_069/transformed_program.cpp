#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt[111];

void check_exponential_growth_invariant(int k) {
    if (k == 4) {
        cerr << "Warning: Performance bottleneck due to exponential growth in subset checking!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int n, int k, int cnt[]) {
    int denseThreshold = n / 2; // a threshold for being considered dense
    int denseCount = 0;
    for (int i = 0; i < (1 << k); i++) {
        if (cnt[i] > denseThreshold) {
            denseCount++;
        }
    }
    if (denseCount > n / 4) { // arbitrary threshold for dense knowledge
        cerr << "Warning: Performance bottleneck due to dense problem knowledge!" << endl;
        abort();
    }
}

void check_problem_knowledge_invariant(int cnt[], int m) {
    bool allKnow = true;
    for (int i = 0; i < m; i++) {
        if (cnt[i] == 0) {
            allKnow = false;
            break;
        }
    }
    if (allKnow) {
        cerr << "Warning: Performance bottleneck due to all teams knowing all problems!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x = 0;
        for (int j = 0; j < k; j++) {
            int t;
            scanf("%d", &t);
            x = x * 2 + t;
        }
        cnt[x]++;
    }
    
    // Insert checks after input processing
    check_exponential_growth_invariant(k);
    check_problem_knowledge_invariant(cnt, 1 << k);
    
    bool ans = false;
    if (cnt[0]) ans = true;
    int m = 1 << k;
    
    // Insert nested loop invariant check before the critical loop
    check_nested_loop_invariant(n, k, cnt);
    
    for (int S = 1; S < (1 << m); S++) {
        int tmp[4], all = 0;
        memset(tmp, 0, sizeof tmp);
        for (int i = 0; i < m; i++)
            if ((S >> i & 1) && cnt[i]) {
                all++;
                for (int j = 0; j < k; j++)
                    if (i >> j & 1) tmp[j]++;
            }
        if (*max_element(tmp, tmp + k) * 2 <= all && all) {
            ans = true;
        }
    }
    puts(ans ? "YES" : "NO");
    return 0;
}