#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 5;
const double EPS = 1e-6;
const long long INF = 1e9;
int a[MAXN];

// Checker functions
void check_low_rank_invariant(int n, int k, int minRank) {
    if (n > 50 && minRank == 1) {
        cerr << "Warning: Low rank invariant triggered - large n with all starting at rank 1" << endl;
        abort();
    }
}

void check_large_nk_invariant(int n, int k) {
    if (n > 90 && k > 90) {
        cerr << "Warning: Large n and k invariant triggered - heavy nested loop processing" << endl;
        abort();
    }
}

void check_rank_distribution_invariant(int n, vector<int>& ranks, int k) {
    int minRank = ranks[0];
    int maxRank = ranks[n-1];
    if (n > 50 && (maxRank - minRank) < (k / 2)) {
        cerr << "Warning: Rank distribution invariant triggered - slow rank increment across soldiers" << endl;
        abort();
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> ranks(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ranks[i]);
    }

    // Insert checks right after input reading
    check_low_rank_invariant(n, k, ranks[0]);
    check_large_nk_invariant(n, k);
    check_rank_distribution_invariant(n, ranks, k);

    if (n == 1) {
        printf("%d", k - ranks[0]);
        return 0;
    }
    bool was;
    for (int i = 0; i < (k * n) + 1; i++) {
        was = false;
        int last = ranks[0];
        for (int j = 1; j < n; j++) {
            if (ranks[j] != last) {
                if (ranks[j - 1] < k) {
                    ranks[j - 1]++;
                    was = true;
                }
            }
            if (j == n - 1) {
                if (ranks[n - 1] < k) {
                    ranks[n - 1]++;
                    was = true;
                }
            }
            last = ranks[j];
        }
        if (!was) {
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}