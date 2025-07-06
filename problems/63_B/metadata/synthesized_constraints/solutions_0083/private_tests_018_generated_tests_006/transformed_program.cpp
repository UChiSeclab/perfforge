#include <bits/stdc++.h>
using namespace std;

// Performance checker functions
void check_majority_low_rank_invariant(int n, const vector<int>& ranks, int k) {
    int lowRankCount = count(ranks.begin(), ranks.end(), 1);
    if (lowRankCount > n / 2 && k > 1) {
        cerr << "Warning: Majority of soldiers starting with rank 1, expect high number of training sessions!" << endl;
        abort();
    }
}

void check_priority_queue_invariant(int n, int k, const vector<int>& ranks) {
    if (n > 50 && (k - ranks.front() <= 1)) {
        cerr << "Warning: Large n with narrow rank range can cause frequent queue operations!" << endl;
        abort();
    }
}

void check_rank_diversity_invariant(int n, const vector<int>& ranks) {
    set<int> uniqueRanks(ranks.begin(), ranks.end());
    if (uniqueRanks.size() < 3) {
        cerr << "Warning: Minimal rank diversity detected, expect inefficient processing!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    while (scanf("%d%d", &n, &k) == 2) {
        vector<int> ranks(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ranks[i]);
        }

        // Applying performance checks
        check_majority_low_rank_invariant(n, ranks, k);
        check_priority_queue_invariant(n, k, ranks);
        check_rank_diversity_invariant(n, ranks);

        int T[100], min = 2e9;
        priority_queue<int> Q;
        for (int i = 0; i < n; i++) {
            Q.push(ranks[i]);
        }
        int ans = 0;
        while (min < k) {
            int prev = -1;
            min = 2e9;
            for (int i = 0; i < n; i++) {
                int cur = Q.top();
                Q.pop();
                if (cur == prev)
                    T[i] = cur;
                else
                    prev = cur, T[i] = cur + 1;
            }
            ans++;
            for (int i = 0; i < n; i++) {
                if (min > T[i]) min = T[i];
                Q.push(T[i]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}