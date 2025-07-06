#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_k_relative_to_coins(int k, const vector<int>& coins) {
    int max_coin_value = *max_element(coins.begin(), coins.end());
    if (k > 3 * max_coin_value) {
        cerr << "Warning: Performance bottleneck condition triggered - k much larger than typical coin values!" << endl;
        abort();
    }
}

void check_high_iteration_count(int n, int k) {
    if (n * k > 150000) {
        cerr << "Warning: Performance bottleneck condition triggered - high nested loop iteration count!" << endl;
        abort();
    }
}

void check_frequent_bitset_updates(int n, int k) {
    if (n > 100 && k > 400) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent bitset evaluations!" << endl;
        abort();
    }
}

void check_coin_value_distribution(const vector<int>& coins) {
    int min_coin = *min_element(coins.begin(), coins.end());
    int max_coin = *max_element(coins.begin(), coins.end());
    if (max_coin - min_coin > 400) {
        cerr << "Warning: Performance bottleneck condition triggered - uneven coin value distribution!" << endl;
        abort();
    }
}

int main() {
    bitset<502> b[502];
    bool ok[502];
    int n, k, c;

    b[0][0] = ok[0] = 1;
    scanf("%d%d", &n, &k);

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &coins[i]);
    }

    // Place checks after reading inputs
    check_large_k_relative_to_coins(k, coins);
    check_high_iteration_count(n, k);
    check_frequent_bitset_updates(n, k);
    check_coin_value_distribution(coins);

    while (n--) {
        c = coins[coins.size() - 1 - n];
        for (int j = k; j >= c; j--) {
            for (int i = 0; i <= k; i++) {
                b[j][i] = (b[j][i] || b[j - c][i] || ((i >= c) ? b[j - c][i - c] : 0));
            }
        }
    }

    printf("%d\n", b[k].count());
    for (int i = 0; i <= k; i++) {
        if (b[k][i]) printf("%d ", i);
    }

    return 0;
}