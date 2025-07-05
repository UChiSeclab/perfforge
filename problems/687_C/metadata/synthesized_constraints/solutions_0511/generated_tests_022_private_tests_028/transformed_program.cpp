#include <bits/stdc++.h>
using namespace std;

void check_total_value_combinations(int k, const vector<int>& coins) {
    int totalCoinValue = accumulate(coins.begin(), coins.end(), 0);
    if (k > totalCoinValue / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - high total coin value combinations!" << endl;
        abort();
    }
}

void check_coin_value_diversity(const vector<int>& coins) {
    unordered_set<int> uniqueValues(coins.begin(), coins.end());
    if (uniqueValues.size() > coins.size() / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - high coin value diversity!" << endl;
        abort();
    }
}

void check_recursive_subset_processing(int k, const vector<int>& coins) {
    int maxCoinValue = *max_element(coins.begin(), coins.end());
    if (k > maxCoinValue * 2) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive recursive subset processing!" << endl;
        abort();
    }
}

void check_large_intermediate_sets(int k, const vector<unordered_set<int>>& fin) {
    for (const auto& set : fin) {
        if (set.size() > k / 2) {
            cerr << "Warning: Performance bottleneck condition triggered - large intermediate result sets!" << endl;
            abort();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n + 1, 0);
    for (int i = 1; i < n + 1; cin >> arr[i++]);
    
    // Run invariant checks on input
    check_total_value_combinations(k, arr);
    check_coin_value_diversity(arr);

    sort(arr.begin(), arr.end());
    vector<vector<unordered_set<int>>> dp(k + 1, vector<unordered_set<int>>(n + 1));
    vector<unordered_set<int>> fin(k + 1);
    fin[0].insert(0);
    dp[0][0].insert(0);
    
    for (int i = 1; i < k + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (i - arr[j] >= 0 && fin[i - arr[j]].size() > 0) {
                int f = 0;
                for (int m = 0; m < j; m++) {
                    for (auto l : dp[i - arr[j]][m]) {
                        if (!fin[i].count(l)) {
                            f = 1;
                            dp[i][j].insert(l);
                            fin[i].insert(l);
                        }
                        if (!fin[i].count(l + arr[j])) {
                            f = 1;
                            dp[i][j].insert(l + arr[j]);
                            fin[i].insert(l + arr[j]);
                        }
                    }
                }
                if (!fin[i].count(arr[j]) && f == 1) {
                    dp[i][j].insert(arr[j]);
                    fin[i].insert(arr[j]);
                }
            }
        }
    }

    // Check before output
    check_large_intermediate_sets(k, fin);
    
    cout << fin[k].size() << endl;
    vector<int> ans;
    for (auto i : fin[k]) ans.push_back(i);
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i << " ";
    cout << endl;
    
    return 0;
}