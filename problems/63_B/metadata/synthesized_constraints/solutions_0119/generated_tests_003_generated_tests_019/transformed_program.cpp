#include <bits/stdc++.h>
using namespace std;
map<int, int> cant;

// Checker for large rank difference
void check_large_rank_difference(int maxRank, int minRank, int threshold) {
    if ((maxRank - minRank) > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to large rank difference!" << endl;
        abort();
    }
}

// Checker for sparse rank distribution
void check_sparse_distribution(const map<int, int>& rankCounts, int k) {
    int gaps = 0;
    for (int i = 1; i < k; ++i) {
        if (rankCounts.find(i) == rankCounts.end()) {
            gaps++;
        }
    }
    int threshold = k / 2; // Example threshold: half of all possible ranks are missing
    if (gaps > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to sparse rank distribution!" << endl;
        abort();
    }
}

// Checker for high maximum rank
void check_max_rank_condition(int k, int threshold) {
    if (k > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to high rank value!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;

    // Run check for high maximum rank condition
    check_max_rank_condition(k, 80); // Threshold of 80 for demonstration

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cant[a]++;
    }

    // Determine the min and max rank from input
    int minRank = cant.begin()->first;
    int maxRank = cant.rbegin()->first;

    // Run check for large rank difference
    check_large_rank_difference(maxRank, minRank, 10); // Threshold of 10 for demonstration

    // Run check for sparse distribution of ranks
    check_sparse_distribution(cant, k);

    bool finished = false;
    int coins = -1;
    cant[0] = -1;
    while (!finished) {
        coins++;
        finished = true;
        for (int i = 1; i < k; i++) {
            if ((cant[i] == 1 && cant[i - 1] == -1) || cant[i] > 1) {
                finished = false;
                cant[i]--;
                if (cant[i + 1] == -1)
                    cant[i + 1] = 1;
                else
                    cant[i + 1]++;
            } else if (cant[i] == 0) {
                cant[i] = -1;
            }
        }
    }
    cout << coins << endl;
}